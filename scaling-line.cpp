//scaling of line using line starting and ending points
//transformation
//scaling
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void plotgraph(int screenWidth, int screenHeight){
	
	for(int i = screenWidth / 2, j = screenWidth / 2;i < screenWidth || j >= 0; i = i + 50, j = j - 50){
		if(i == screenWidth / 2) {
			setcolor(WHITE);
			line(i,0,i,screenHeight);
		}
		else {
			setcolor(WHITE);
			line(i,0,i,screenHeight);
			line(j,0,j,screenHeight);
		}
	}
	
	for(int i = screenHeight / 2, j = screenHeight / 2;i < screenHeight || j >= 0; i = i + 50, j = j - 50){
		if(i == screenHeight / 2) {
			setcolor(WHITE);
			line(0,i,screenWidth,i);
		}
		else {
			setcolor(WHITE);
			line(0,i,screenWidth,i);
			line(0,j,screenWidth,j);
		}
	}
}

int main()
{

   

    float x,y,x0,y0,x1,y1,sx,sy;
    int i;

    cout<<"Enter the value of starting point (x0,y0): ";
    cin>>x0>>y0;
    cout<<"Enter the value of ending point (x1,y1): ";
    cin>>x1>>y1;
    cout<<"Enter the value of scaling factor (sx,sy): ";
    cin>>sx>>sy;
	 DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, "", -3, -3);
	plotgraph(screenWidth, screenHeight);

//line before scaling
    setcolor(YELLOW);
    line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
    outtextxy((screenWidth/2)+x1,(screenHeight/2)-y1+10, "Before Scaling");

//calculating the  coordinates
    x0=x0*sx;
    y0=y0*sy;
    x1=x1*sx;
    y1=y1*sy;
    
    cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1;

    setcolor(GREEN);
    line((screenWidth/2)+x0,(screenHeight/2)-y0,(screenWidth/2)+x1,(screenHeight/2)-y1);
	outtextxy((screenWidth/2)+x1,(screenHeight/2)-y1+10, "After Scaling");
	
	delay(500);
    getch();
    closegraph();
}