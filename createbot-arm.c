#include <kipr/botball.h>
int x;//declares variable
int main()
{
    x=0;//defines variable
    create_connect();//start robot motors
    enable_servos();//start servos
    
    set_servo_position(0,1000);//start position 1
        msleep(1000);
    
    set_servo_position(1,2047);//start position 2
        msleep(1000);
    
    set_servo_position(2,1000);//start position 3
        msleep(1000);
    
    while (x < 100);//used a variable for precision of robot movement
    {
        create_drive_direct(75,75);//go straight
        msleep(1000);
        x++;
    }
        
        set_servo_position(0,2047);//servos move to secondary position 1
        msleep(1000);
        
        set_servo_position(1,0);//servos move to secondary position 2
        msleep(1000);
        
        set_servo_position(2,1500);//servos move to secondary position 3
        msleep(1000);
    
    		msleep(5000);
    			
    set_servo_position(0,1000);//start position 1
        msleep(1000);
    
    set_servo_position(1,2047);//start position 2
        msleep(1000);
    
    set_servo_position(2,1000);//start position 3
        msleep(1000);
        
    
    disable_servos();//servo shutdown
    create_stop();
    create_disconnect();//robot shutdown
    return 0;
}
