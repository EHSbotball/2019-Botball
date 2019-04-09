#include <kipr/botball.h>
int a = 0;//counter 1
int b = 1;//counter 2
int c = 3800;//analog 5 sense black
int d = 3800;//analog 1 sense black
int e = 2200;//grey
int x = 800;
int y = 950;
int z = 1; // for wavy bit
int main()
{  //start position is 9 1/4 in. from perimeter
    camera_open_black();
    enable_servos();
    set_servo_position(2,700);//start position
    set_servo_position(3,1750);
    msleep(1600);
    motor(0,-25);
    motor(2,25);
    msleep(1400);
    //go past the first black line
        motor(0,50);
        motor(2,50);
        msleep(2000);
        ao();
    //go to the second black line
    while(analog(1) < c)//use c for value of analog5 sensing black
    {
        motor(0,50);
        motor(2,50);
        msleep(600);
          ao();
    }
    motor(0,40);
      motor(2,25);
      msleep(4000);
    while(analog(1) < d)
    { motor(0,40);
      motor(2,25);
      msleep(200);
      ao();
    }
    motor(2,50);
    motor(0,50);
    msleep(2500);
   while(analog(1) < 3800)
   {
       while ( z == 1 || z == 2 )
       {
       motor(0,60);
      motor(2,5);
      msleep(150);
      z = z + 1;
      printf("printa"); //for troubleshooting
      ao();
       }
        if (z == 4 || z == 3)
       {
       motor(2,60);
      motor(0,5);
      msleep(150);
          z++;
         printf("printb"); //for troubleshooting 2
        }
       if( z == 5)
       { 
           z = 1;
       }
           
   }
  
    motor(2,40);
    motor(0,10);
    msleep(700);
    ao();
    motor(2,20);
    motor(0,20);
    msleep(1900);
    ao();
    motor(0,-20);
    motor(2,-20);
    msleep(100);
    ao();
    //getting the ring off the tube
    set_servo_position(0,1000);//default pos
    msleep(500);
    set_servo_position(2,700);
    msleep(500);
    set_servo_position(3,y);
    msleep(500);
    
    set_servo_position(0,2000);
    msleep(500);
    set_servo_position(3,y);
    msleep(850);
    cmpc(0);

    while(a < 150)//gets cylinder off tube
    {
     a = gmpc(0);
     motor(0,5);
     motor(2,5);
     msleep(200);
        ao();
    set_servo_position(3,x);
        x = x + 120;
        msleep(200);
    }
    motor(0,-50);
    motor(2,-50);
    msleep(500);
    ao();
    
   
    //default pos
    msleep(500);
    set_servo_position(2,1300);
    msleep(500);
    msleep(500);
    
    
 
    set_servo_position(2,1855);
    msleep(500);
     while(analog(1) < d)
    { motor(0,-40);
      motor(2,-25);
      msleep(200);
      ao();
    }
      motor(2,70);
      motor(0,25);
      msleep(2000);
      while(analog(1) < d)
    { motor(2,50);
      motor(0,30);
      msleep(200);
      ao();
    }
    
    set_servo_position(3,1450);//move to height of tube
    motor(0,25);//move to tube
    motor(2,25);
    msleep(6550);
    ao();
    motor(2,25);
    msleep(2000);
    ao();
    set_servo_position(0,1300);
    set_servo_position(3,1400);
    msleep(200);
    motor(2,-25);
    msleep(2000);
    
    camera_close();
    disable_servos();
    return(0);

}

