#include <iostream>

using namespace std;

class Exam {

	private:
	    char* student_name;
	    char* exam_date;
	    int score;
	
	public:
	    
	    Exam(const char* name, const char* date, int s) {
	        
	        int len_name = 0;
	        while (name[len_name] != '\0') len_name++;
	
	        int len_date = 0;
	        while (date[len_date] != '\0') len_date++;
	
	        student_name = new char[len_name + 1];
	        exam_date = new char[len_date + 1];
	
	        for (int i = 0; i < len_name; i++) {
	            student_name[i] = name[i];
	        }
	        student_name[len_name] = '\0';
	
	        for (int i = 0; i < len_date; i++) {
	            exam_date[i] = date[i];
	        }
	        exam_date[len_date] = '\0';
	
	        score = s;
	    }
	
	    ~Exam() {
	        delete[] student_name;
	        delete[] exam_date;
	    }
	
	    void display() const {
	        cout << "Student: " << student_name << ", Exam Date: " << exam_date << ", Score: " << score << endl;
	    }
};

int main() {
    Exam exam1("Huzaifa", "11-Sep-2025", 88);
    exam1.display();
    Exam exam2 = exam1; 
    exam2.display();

    return 0;
}
