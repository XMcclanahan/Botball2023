#include <kipr/wombat.h>

int main()
{
    create_connect();
    while(get_create_rcliff_amt()>2000 && get_create_lcliff_amt()>2000)
    {
        printf("%d\n",get_create_rcliff_amt());
        msleep(10);
        while(get_create_rfcliff_amt()>2000)
        {
            create_drive_direct(150,50);
        }
        while(get_create_rfcliff_amt()<2000)
        {
            create_drive_direct(50,150);
        }
    }
    if(get_create_rcliff_amt()<2000 || get_create_lcliff_amt()<2000)
    {
        while(get_create_rcliff_amt()>1800)
        {
            create_drive_direct(-50,150);
        }  
        while(get_create_lcliff_amt()<1800)
        {
            create_drive_direct(150,-50);
        }
        if(get_create_rcliff_amt()<2000 && get_create_lcliff_amt()<2000)
        {
            create_disconnect();
        }  
    } 
    create_disconnect();   
    return 0;
}
