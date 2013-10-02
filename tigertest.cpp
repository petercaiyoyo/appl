/**
  @brief  a example client file for the appl package
  @author Shaoujun Cai 
  @date 2013-05-10
**/
#include<iostream>
#include<time.h>
#include "ros/ros.h"
#include "appl/appl_request.h"
using namespace std;
int obs[8]={0,1,0,1,0,1,0,0};
int main(int argc,char**argv)
{

	/*ros initializations*/
	ros::init(argc,argv,"tiger");
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<appl::appl_request>("appl_request");
	
	srand((unsigned)time(0));
	int tiger;//0=left 1=right
	tiger=rand()%2;
	
	appl::appl_request srv;
	srv.request.cmd=1;	//reset the controller first
	client.call(srv);
	int action=srv.response.action;
	ROS_INFO("%d",action);
	
	string state_str;
	int i;
	char rob_vel_str[30];
	for(i=0;i<8;i++)
	{
		if(obs[i]==0)		//left
		{
			state_str="obs-left";
		}
		else
		{
			state_str="obs-right";
		}
		srv.request.cmd=2;
		srv.request.obs=state_str;
		client.call(srv);
	}
}
