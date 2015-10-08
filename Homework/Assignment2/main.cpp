//#include <QCoreApplication>
#include "simplevector.h"
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    SimpleVector<int> v(5);
    v.fillVector();
    cout<<"Would you like to stop, pull, or pop?\n";
    cout<<"Enter 0 for stop, 1 for pull, 2 for pop.\n";
    int num;
    do{
        cin>>num;
        if(num==1){
            v.pullVector();
        }
        if(num==2){
            v.pushVector();
        }
    }while(num!=0);

    //return a.exec();
    return 0;
}
