 ///
 /// @file    Hellolog4cpp.cc
 /// @author  zhy(GitHub:Charles-joy)
 /// @date    2018-04-15 15:55:13
 ///
//编译：g++ Hellolog4cpp -o helloword -llog4cpp -lpthread
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using namespace std;

int main(int argc,char* argv[])
{
	log4cpp::OstreamAppender* osAppender= new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new log4cpp::BasicLayout());//创建一个Appender,并指定其包含的Layout
	log4cpp::Category& root =log4cpp::Category::getRoot();//从系统中得到category的根，将Appender添加到category中
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);//设置category优先级
	//记录日志
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");
	//关闭Category
	log4cpp::Category::shutdown();
	return 0;
}

