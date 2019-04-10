#include <kipr/botball.h>
int    x;
double bias;
int    pos;
double area;

/**
* Averages the error in the gyro for the z axis.
*/
void   calibrate_gyro()
{
    double avg = 0;
    int i = 0;
    while(i < 50)
    {
        avg += gyro_z();
        msleep(10);
        i++;
    }
    bias = avg / 50.0;
    printf("New Bias: %f\n", bias);
}

/**
* Uses the gyro to turn the create at a certain speed to a certain degree.
*/
void gyro_turn(int speed, double targetAngle)
{
    double targetTheta = (targetAngle/90) * 600000;
    double theta = 0;
    if(targetAngle > 0)
    {
        create_spin_CW(speed);
        while(theta < targetTheta)
        {
            msleep(10);
            theta += abs(gyro_z() - bias) * 10;
        }
        create_stop();
    }
    else
    {
        create_spin_CCW(speed);
        while(theta > targetTheta)
        {
            msleep(10);
            theta -= abs(gyro_z() - bias) * 10;
        }
        create_stop();
    }
}

/**
* moves servo to position moving less and less distance as it aproaches the target position
*/
void slow_servo(int servo, int position)
{
    double move_servo = position - get_servo_position(servo);
    while( move_servo - 5 > 0  )
    {
    	set_servo_position(servo, get_servo_position(servo) + move_servo/3);
        msleep(500);
        move_servo = position - get_servo_position(servo);
    }
    while (move_servo + 5 < 0)
    {
        set_servo_position(servo, get_servo_position(servo) + move_servo/3);
        msleep(100);
        move_servo = position - get_servo_position(servo);
    }
}
int main()
{
    create_connect();
    enable_servos();
    calibrate_gyro();
    camera_open_black();
    
    //lift the arm half way
    set_servo_position(0,800);
    msleep(1000);
    
    //lifts the arm all the way
    set_servo_position(0,0);
    
    //opens the claw
    set_servo_position(1,2040);
    msleep(1000);
    
    //turns create towards water cube
    gyro_turn(100, 50);
    
    //drive to water cube
    create_drive_straight(-200);
    msleep(1800);
    
    // turn to align claw with water cube
    gyro_turn(100,95);
    msleep(1000);
    
    //slowly move the arm to grab the water cube
    slow_servo(0,1600);
    
    //close claw
    set_servo_position(1,550);
    msleep(1000);
    
    //raise arm
    set_servo_position(0,0);
    msleep(1000);

    //turn towards towers
    gyro_turn(100,-5);
    
    //drive straight towards towers
    create_drive_straight(-200);
    msleep(3000);
    
    //turn to drive parallel to towers
    gyro_turn(100,-90);
    
    //Use the camera to see what building is on fire
    while (x < 1)
    {
    	camera_update();
    	area = get_object_area(0,0);
        center = get_object_center_x(0,0);
    	if(area > 100 && (center < 90 || center > 70));
    	{
    	    printf("Hey it's there.");
            set_servo_position(1,2040);
            x++;
    	}
    	else
    	{
    		create_drive_straight(100);
        	msleep(100);
    	}
    }
    disable_servos();
    create_disconnect();
    
    return 0;
}

