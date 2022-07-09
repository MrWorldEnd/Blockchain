#include "IPlistmanager.h"

using namespace std;

IPlist::IPlist(){
    stack<Device> x;
    list = x;
}

void IPlist::addtolist(Device x){
    list.push(x);
}

void IPlist::print(stack<Device> res){
    stack<Device> tmp;
    Device x;

    tmp = res;

    // If stack is empty
    if (tmp.empty())
        return;
 
// Extract top of the stack
    x = tmp.top();
 
    // Pop the top element
    tmp.pop();
 
    // Print the current top
    // of the stack i.e., x
    cout << x << ' ';
 
    // Proceed to print
// remaining stack
    print(tmp);
 
    // Push the element back
    tmp.push(x);

}

void PrintStack(stack<int> s)
{
}