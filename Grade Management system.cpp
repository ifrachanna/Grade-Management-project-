#include <iostream>
#include <iostream>
#include <vector>
#include <fstream> 
#include <sys/stat.h>
using namespace std;
struct Student{
	string name;
	int marks1,marks2,marks3;
	double total;
	char grade;
	double average;

  void getdata(){
  
  cout<<"Enter the name:";
   cin.ignore();
  getline(cin,name);
  
  cout<<"Enter the Subject1:";
  cin>>marks1;
  cout<<"Entre the subject2:";
  cin>>marks2;
  cout<<"Enter the Subject3:";
  cin>>marks3;
}
 void calculateResult(){
 	total=marks1+marks2+marks3;
 	average= total/3.0;
 	
 	
 	if (average>=90){
 		grade= 'A';
	 }
	 else if( average>=80){
	 	grade= 'B';
	 }
	 else if (average>=70){
	 	grade= 'C';
	 }
	 else{
	 	grade= 'D';
	 }
 	
 }
 void desplay(){
 	cout << "\n===== Student Report =====" << endl;
 	cout<<"Name of the Student is="<<name<<endl;
 	cout<<"Total marks of Student="<<total<<"/300"<<endl;
 	cout<<"Average of a Student="<<average<<"%"<<endl;
 	cout<<"Grade of a Student="<<grade<<endl;
 	cout << "Status: " << (grade == 'F' ? "? Fail" : "? Pass") << endl;
 		
 }
 
 string toCSV() {
        return name + "," + to_string(marks1) + "," + to_string(marks2) + "," +
               to_string(marks3) + "," + to_string(total) + "," +
               to_string(average) + "," + grade;
    } 
};
bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}


 	int main() {
    vector<Student> students;
    int n;

    cout << "How many students? ";
    cin >> n;

    // ?? Step 1: Input and calculate for all students
    for (int i = 0; i < n; ++i) {
        Student s;
        s.getdata();
        s.calculateResult();
        students.push_back(s);
    }

    
    for (int i = 0; i < students.size(); ++i) {
        students[i].desplay();
    }

    
    string filename = "student_results.csv";
    bool exists = fileExists(filename);  

    ofstream file(filename.c_str(), ios::app);  

    if (!exists) {
        file << "Name,Subject1,Subject2,Subject3,Total,Average,Grade\n";
    }

    for (int i = 0; i < students.size(); ++i) {
        file << students[i].toCSV() << "\n";
    }

    file.close();
    cout << "\n? Results appended to student_results.csv.\n";

    return 0;
}

