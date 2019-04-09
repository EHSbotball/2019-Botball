#include <kipr/botball.h>
double x;
double bias;
int    pos;
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
int main()
{
    create_connect();
    enable_servos();
    calibrate_gyro();
    camera_open_black();
    
    set_servo_position(0,800);
    msleep(1000);
    
    set_servo_position(0,0);
    
    set_servo_position(1,2040);
    msleep(5000);
    
    gyro_turn(100, 50);
    
    /* camera_update();
    
    double area = get_object_area(0,0);
    if(area < 100);
    {
        printf("Hey it's not there dumbass");
        pos = 0;
    }
    else
    {
    	x = get_object_center(0,0);
    	if(x < 90)
    	{
       		pos = 1;
    	}
        else
        {
            pos = 2;
        }
    } */
    
    create_drive_straight(-200);
    msleep(2000);
    
    gyro_turn(100,90);
    msleep(2000);
    
    set_servo_position(0,900);
    msleep(1000);
    
    set_servo_position(0,1500);
    msleep(1000);
    
    set_servo_position(1,1000);
    msleep(1000);
    
    set_servo_position(0,0);
    msleep(1000);
    
    create_drive_straight(-200);
    msleep(3000);
    
    gyro_turn(100,-90);
    
    disable_servos();
    create_disconnect();
    
    return 0;
}

