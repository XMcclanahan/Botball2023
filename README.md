# Botball2023
include <kipr/wombat.h>
#include <Global variables.h>
/*void go_straight(int dist);
void L_turn(int degree);
void R_turn(int degree);
void go_back(int dist);
void MasS_movearm(int dist);
void go_Straight_till_bump();
void arm_down();
void mas_armdown(int dist);
void square_up(int gray);*/
void start_go_back(int dist);
void start();
//void line_follow(int grey);
void line_follow2(int grey);
//void go_till_black(int black);
void arm_down();
void camera_cube(int size);
void grab_cube();

int main()
{
    wait_for_light(0);
    shut_down_in(119);
    create_connect();
    enable_servos();
    set_servo_position(1,1600);
    //square up with first black line(variable is number between black and white values)
    square_up(2000);
    go_straight(50);
    //go tillsecond black line
    //go_till_black(2000);
    square_up(2000);
    go_straight(50);
    //square up on third black line
    square_up(2000);
    /* L_turn(20);
    go_straight(450);
    R_turn(55);*/
    //sets claw, moves toward cube then turns on camera, moves toward cube and grabs cube
    grab_cube();
    //
    msleep(500);
    go_back(-150);
    msleep(500);
    L_turn(90);
    square_up(2000);
    L_turn(88);
    line_follow(2300);
    go_straight(50);
    line_follow2(2300);
	set_servo_position(2,1250);
    msleep(500);
    go_straight(150);
    R_turn(15);
    //line_follow(2000);


    create_disconnect();
    return 0;
}

/*void go_straight(int dist)
{
    //create_connect();
    set_create_distance(0);
    while(get_create_distance() < dist)
    {
        create_drive_direct(200,200);
        msleep(50);
    }
    create_stop();
    //create_disconnect();
}

void L_turn(int degree)
{
    //create_connect();
    set_create_total_angle(0);
    while (get_create_total_angle() < degree)
    {
        create_drive_direct(-100,100);
        msleep(50);
    }
    create_stop();
}

void R_turn(int degree)
{
    //create_connect();
    set_create_total_angle(0);
    while(get_create_total_angle() > -degree)
    {
        create_drive_direct(200,-200);
    }
    create_stop();
}

void go_back(int dist)
{
    //create_connect();
    set_create_distance(0);
    while(get_create_distance() > dist) //need to have negative distance 
    {
        create_drive_direct(-200,-200);
        msleep(10);
    }
    create_stop(); 
}

void MasS_movearm(int dist)
{
    cmpc(0);
    while(gmpc(0) < dist)
    {
        motor(0,100);
    }
    ao();
}

void go_Straight_till_bump()
{

    //create_connect();


    while((get_create_rbump() == 0) && (get_create_lbump() == 0))
    {
        create_drive_direct(200,200);
        msleep(50);
    }
    create_stop();
    //create_disconnect();
}

//void Claw_code
void arm_down()
{
    while (digital(0)==0)
    {
        mav(0,-1000);
    }
    ao();
    while (digital(0)==1)
    {
        mav(0,1000);
        msleep(500);
        ao();
    }
}
void mas_armdown(int dist)
{
    while(gmpc(0) > dist )
    {
        motor(0,-100);
    }
    ao();
}
void square_up(int gray)
{
    while (1){
        if(get_create_lcliff_amt()> gray && get_create_rcliff_amt()> gray)
        {
            create_drive_direct(200,200);
        }
        if(get_create_rcliff_amt()< gray)
        {
            create_drive_direct(200,0);
        }
        if(get_create_lcliff_amt()< gray)
        {
            create_drive_direct(0,200);
        }
        if(get_create_lcliff_amt()< gray && get_create_rcliff_amt()< gray)
        {
            create_drive_direct(0,0);
            break;
        }
    }
}*/
void start_go_back(int dist)
{
    set_create_distance(0);
    while (get_create_distance()>dist)
    {
        create_drive_direct(-200,-200);

    }
    create_stop();
}

void start()
{
    square_up(2100);
    create_drive_direct(-200,-200);
    msleep(500);
    start_go_back(-450);
    R_turn(92);
}
/*void line_follow(int grey)
{
    while(get_create_rcliff_amt()>grey)
    {
        if(get_create_rfcliff_amt()>grey)
        {
            create_drive_direct(150,75);
        }
        if(get_create_rfcliff_amt()<grey)
        {
            create_drive_direct(75,150);
        }
    }
}*/
void line_follow2(int grey)
{
    while(get_create_lcliff_amt()>grey)
    {
        if(get_create_rfcliff_amt()>grey)
        {
            create_drive_direct(150,75);
        }
        if(get_create_rfcliff_amt()<grey)
        {
            create_drive_direct(75,150);
        }
    }
}
/*void go_till_black(int black)
{
    while(get_create_lcliff_amt()> black)
    {
        create_drive_direct(300,300);
        msleep(50);
    }
    create_stop();
}*/
void arm_down()
{
    set_servo_position(1,980);
}

void camera_cube(int size)
{
    camera_open();
    msleep(500);
    // camera_update();
    //printf("%d\n",get_object_bbox_width(0,0));

    while(get_object_bbox_width(0,0)<size) 
    {
        //camera_update();
        while(get_object_center_x(0,0)>85 ||get_object_center_x(0,0) <75)
        {
            camera_update();
            if(get_object_center_x(0,0)<75)
            {
                create_drive_direct(-50,50);
            }
            if(get_object_center_x(0,0)>75)
            {
                create_drive_direct(50,-50);
            }
        }
        printf("%d\n",get_object_bbox_width(0,0));
        create_drive_direct(150,150); 
        camera_update();
    }   
}

void grab_cube()
{
    arm_down();
    set_servo_position(2,1350);
    msleep(500);
    set_create_distance(0);
    go_straight(517);
    if(get_create_rlightbump()==1)
    {
        L_turn(5);
    }
    msleep(500);
    camera_cube(78);
    //go_straight(80);
    printf("Am I here?");
    msleep(500);
    set_servo_position(2,450);
}
