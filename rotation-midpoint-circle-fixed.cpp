//midpoint circle draw
//rotation 
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int screenWidth,screenHeight;
void plotgraph(int screenWidth,int screenHeight)
{
	//plotting grids
	for(int i=screenWidth/2;i<=screenWidth;i=i+25)
	{
		for(int j=screenHeight/2;j<=screenHeight;j=j+25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	for(int i=screenWidth/2;i>=0;i=i-25)
	{
		for(int j=screenHeight/2;j>=0;j=j-25)
		{
			setcolor(WHITE);
			line(0,j,screenWidth,j);
			line(i,0,i,screenHeight);
		}
	}
	//plotting origin axes
	setcolor(YELLOW);
	line(0,screenHeight/8,screenWidth,screenHeight/8);
	line(screenWidth/8,0,screenWidth/8,screenHeight);
}

void call(float x, float y,float xc, float yc,float pk ){

	 while(x<=y)
    {
        setcolor(GREEN);
        putpixel((screenWidth/8)+(xc+x),(screenHeight/8)-(yc+y),GREEN);
        putpixel((screenWidth/8)+(xc+x),(screenHeight/8)-(yc-y),GREEN);
        putpixel((screenWidth/8)+(xc-x),(screenHeight/8)-(yc+y),GREEN);
        putpixel((screenWidth/8)+(xc-x),(screenHeight/8)-(yc-y),GREEN);
        putpixel((screenWidth/8)+(xc+y),(screenHeight/8)-(yc+x),GREEN);  
        putpixel((screenWidth/8)+(xc+y),(screenHeight/8)-(yc-x),GREEN);
        putpixel((screenWidth/8)+(xc-y),(screenHeight/8)-(yc+x),GREEN);
        putpixel((screenWidth/8)+(xc-y),(screenHeight/8)-(yc-x),GREEN);
        
      
        if(pk<0)
        {
        	x=x+1;
        	y=y;
        	pk=pk+2*x+1;
		}
		else
		{
			x=x+1;
        	y=y-1;
        	pk=pk+2*x+1-2*y;
		}
	
	}
}
int main(){
	
	float x,y,r,xc,yc,x1,y1,dx,dy,pk,radian,angle;

	cout<<"Enter the value of radius r : ";
	cin>>r;
	cout<<"Enter the value of center point (xc,yc): ";
	cin>>xc>>yc;
	cout<<"Enter the rotation angle a: ";
	cin>>angle;
	
    //graphics driver
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)" ");
	
	//window size measurement and initialization
	 screenWidth=GetSystemMetrics(SM_CXSCREEN);
	  screenHeight=GetSystemMetrics(SM_CYSCREEN);
	 
	
	//graph plotting function call
	plotgraph(screenWidth,screenHeight);
	radian=angle*3.14/180;
	
	
	x=0;
	y=r;
	
	if(r- (int)r==0.0)
	{
		pk=1-r;          //initial value of decision parameter pk
	}
	else
	{
		pk=(5.0/4.0-r);
	}
	
	
//	cout<<"x\ty"<<endl;	
    
   call(x, y,xc,yc,pk);
	
    outtextxy((screenWidth/8)+xc,(screenHeight/8)-yc+10, "before rotation");
   
    
    setcolor(BLUE);
	float x_, y_;
	 x_=x;
	 y_=y;

	x= (x)*cos(radian) -y*sin(radian)+10 ;
	y= (x)*sin(radian) +y*cos(radian)+10 ;
   call(x, y,xc,yc,pk);
    // outtextxy((screenWidth/2)+(xc+x)*cos(radian)-(yc+y)*sin(radian)+10,(screenHeight/2)-(xc+x)*sin(radian)+(yc+y)*cos(radian)-10, "after rotation");
    outtextxy((screenWidth/8)+5,(screenHeight/8)+5, "(0,0)");
	getch();
	closegraph();
	

}