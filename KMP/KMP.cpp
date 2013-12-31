#include <iostream>
#include <string>
#include <vector>

//getNext
//k=next[j];p[j+1]!=s[i+1]
//         k+1;                                       (p[k]=p[j])
//next[i]= 
//         next[k]+1(and p[next[k]=p[j]])             (p[k]!=p[j]) 

bool getNext(int *next,std::string subStr){
	if(subStr.size()<=0){
		std::cout<<"The subStr is empty: ";
		return false;
	}
	std::string::size_type i=0;
	int j=-1;
	next[0]=-1;
	while(i<subStr.size()-1){
		if(j==-1||subStr[i]==subStr[j]){
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}
	return true;

}
//Optimized getNext
bool ogetNext(int *next,std::string subStr){
	if(subStr.size()<=0){
		std::cout<<"The subStr is empty: ";
		return false;
	}
	std::string::size_type i=0;
	int j=-1;
	next[0]=-1;
	while(i<subStr.size()-1){
		if(j==-1||subStr[i]==subStr[j]){
			++i;
			++j;
			if(subStr[i]!=subStr[j]){
				next[i]=j;
			}
			else {
				next[i]=next[j];
			}
		}
		else
			j=next[j];
	}
	return true;

}

//getPosition
bool getPosition(int *next,std::string mStr,std::string subStr,std::string::size_type &pos)
{
	int m=mStr.size();
	int sub=subStr.size();
	std::string::size_type i=pos;
	int j=0;
	while( i<mStr.size()&& j<int(subStr.size()) )
	{
		if( j==-1 || mStr[i]==subStr[j] )
		{
			++i;
			++j;
		}
		else 
		{
			j=next[j];
		}
	}  
	if(j==sub)
	{
		pos=i-subStr.size();
		std::cout<<"Match position is: "<<pos;
		return true;
	}
	else 
	{
		std::cout<<"No match!";
		return false;
	}

}



void main()
{
	//main string
	std::cout<<"Please input the main string: ";
	std::string mStr;
	std::cin>>mStr;

	//subStr 
	std::cout<<"Please input the substring: ";
	std::string subStr;
	std::cin>>subStr;

	//getNext
	int *next=new int[subStr.size()];
	ogetNext(next,subStr);
	for (std::string::size_type i=0;i<subStr.size();i++){
		std::cout<<next[i]<<" ";
	}
	std::string::size_type pos=0;
	getPosition(next,mStr,subStr,pos);
	
	system("pause");
}