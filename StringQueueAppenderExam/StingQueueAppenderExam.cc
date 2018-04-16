 ///
 /// @file    StingQueueAppenderExam.cc
 /// @author  zhy(GitHub:Charles-joy)
 /// @date    2018-04-15 20:01:44
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/StringQueueAppender.hh>
using namespace std;
int main(int argc,char* argv[])
{
	log4cpp::StringQueueAppender* strQAppender =new log4cpp::StringQueueAppender("strQAppender");
	strQAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root=log4cpp::Category::getRoot();
	root.addAppender(strQAppender);
	root.setAppender(strQAppender);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");

	cout << "Get Message from Message Queue!" << endl;
	cout << "------------------------------------------------" << endl;
	queue<string>& myStrQ =strQAppender->getQueue();
	while(!myStrQ.empty())
	{
		cout << myStrQ.front();
		myStrQ.pop();
	}

	log4cpp::Category::shutdown();
	return 0;

		
}
