//Assignment 1 Question 1
//Neil MacKenzie
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Functions relating to Question 1
void getFractions(int arr[]);
void calcFractions(int arr[]);
void reduceFractions(int arr[]);
void showFractions(int arr[]);

//Functions relating to Question 2
void readFile(string arrS[], int arr[][100]);
void calculateAverage(string arrS[], int arr[][100], float stuAvg[]);
char calculateGrade(float studAvg);
void calculateTestAverage(int testScore[][100], float testAvg[]);
void printGrades(string nameStu[], int testScore[][100], float stuAvg[], char stuGrade[], float testAvg[]);

int main()
{
	string progResp = "Y";
	int x = 0;
	int y;

	//Menu system for programs
	do {
		cout << "Which program would you like to run?" << endl;
		cout << "1. Fraction Calculator" << endl;
		cout << "2. Grading Schema" << endl;
		cout << "3. Biggest Integer" << endl;
		cout << "4. Exit program" << endl;
		cin >> progResp;

		//Question 1
		if (progResp == "1"){
			string userResp = "Y";

			//Array of numerators and denominators
			int fraction[12];

			do {
				getFractions(fraction);
				calcFractions(fraction);
				reduceFractions(fraction);
				showFractions(fraction);
				cout << "Do you want to compute another fraction? y/n" << endl;
				cin >> userResp;
				system("cls");
			} while (userResp == "y" || userResp == "Y");
			progResp = "Y";
		}

		//Question 2
		else if (progResp == "2"){
			string nameStu[100];
			int testScore[100][100];
			float stuAvg[100];
			char stuGrade[100];
			float testAvg[100];

			system("cls");
			readFile(nameStu, testScore);
			calculateAverage(nameStu, testScore, stuAvg);
			
			for (int x = 0; x < 100; x++){
				stuGrade[x] = calculateGrade(stuAvg[x]);
			}
			
			calculateTestAverage(testScore, testAvg);
			printGrades(nameStu, testScore, stuAvg, stuGrade, testAvg);

			progResp = "Y";
		}

		//Question 3
		else if (progResp == "3"){
			vector <int> q3Num;
			vector <float> q3NumVal;

			int counter = 1;
			string q3ask = "n";
			bool badResp = false;

			//clear screen
			system("cls");
			do{
				cout << "Please enter a number in the range of 1-99" << endl;
				cin >> x;
				if (x > 0 && x < 100){
					counter++;
					q3Num.push_back(x);

					if (x < 10){
						q3NumVal.push_back((float)x / (float)9);
					}
					else{
						q3NumVal.push_back((float)x / (float)99);
					}

				}
				else {
					cout << "That was not a number between 1 and 99" << endl;
					badResp = true;
				}

				//Makes sure it does ask you if you're finished if you entered the maximum
				//amount of responses or if you entered an invalid response
				if (counter <= 10 && badResp == false){
					cout << "Finished? y/n?" << endl;
					cin >> q3ask;
					if (q3ask == "Y" || q3ask == "y"){
						counter = 11;
					}
				}

				//Resets badResp value
				if (badResp)
				{
					badResp = false;
				}


			} while (counter <= 10);

			//Buble sorting the vectors
			float temp1;
			int temp2;
			bool finished = false;

			while (!finished){
				finished = true;
				for (int i = 0; i < q3NumVal.size() - 1; i++){
					if (q3NumVal[i] < q3NumVal[i + 1]){
						//Sorting number values
						temp1 = q3NumVal[i];
						q3NumVal[i] = q3NumVal[i + 1];
						q3NumVal[i + 1] = temp1;
						//Sorting numbers
						temp2 = q3Num[i];
						q3Num[i] = q3Num[i + 1];
						q3Num[i + 1] = temp2;
						//Ends the while loop
						finished = false;
					}
				}
			}

			cout << "\t" << "The biggest number possible is : ";
			for (int i = 0; i < q3Num.size(); i++){
				cout << q3Num[i];
			}
			cout << endl << endl << endl;

			q3ask = "y";

			progResp = "Y";
		}
		else if (progResp == "4"){
			cout << endl << "\tFour was chosen" << endl << endl;
		}
		else{
			cout << endl << "\tPlease choose again" << endl << endl;
			progResp = "Y";
		}
	} while (progResp == "y" || progResp == "Y");
	return 0;
}

void getFractions(int arr[])
{
	system("cls");
	cout << "PLEASE ENTER YOUR FRACTIONS BELOW" << endl;
	cout << "What is the numerator for the first fraction?" << endl;
	cin >> arr[0];
	cout << "What is the denominator for the first fraction" << endl;
	cin >> arr[1];
	cout << "What is the numerator for the second fraction?" << endl;
	cin >> arr[2];
	cout << "What is the denominator for the second fraction" << endl;
	cin >> arr[3];

	cout << "You chose " << arr[0] << "/" << arr[1] << " and " << arr[2] << "/" << arr[3] << endl;
}



void calcFractions(int arr[])
{
	//Multiplication
	cout << "multiplication\n";
	arr[4] = arr[0] * arr[2];
	arr[5] = arr[1] * arr[3];
	cout << arr[4] << "/" << arr[5] << endl;

	//Division
	cout << "division\n";
	arr[6] = arr[0] * arr[3];
	arr[7] = arr[1] * arr[2];
	cout << arr[6] << "/" << arr[7] << endl;

	//Addition
	cout << "addition\n";
	arr[8] = arr[3] * arr[0] + arr[1] * arr[2];
	arr[9] = arr[1] * arr[3];
	cout << arr[8] << "/" << arr[9] << endl;

	//Subtraction
	cout << "subtraction\n";
	arr[10] = arr[3] * arr[0] - arr[1] * arr[2];
	arr[11] = arr[1] * arr[3];
	cout << arr[10] << "/" << arr[11] << endl;
}

void reduceFractions(int arr[])
{
	int a, b, e, gcd;
	a = 0;
	b = 0;
	e = 0;
	gcd = 1;

	for (int i = 4; i < 12; i = i + 2)
	{
		a = arr[i];
		b = arr[i + 1];

		//makes sure variable 'a' is the larger than variable 'b'
		if (a < b){
			e = a;
			a = b;
			b = e;
		}

		if (b != 0 && b != 1 && b != a){
			for (int i = b; i > 1; i--){
				if (a%i == 0 && b%i == 0){
					gcd = i;
					//Breaks for loop, so that GCD calculation doesn't continue to run and GCD overwritten
					i = 0;
				}
			}

			//Run inside this if statement to avoid dividing by zero
			arr[i] = arr[i] / gcd;
			arr[i + 1] = arr[i + 1] / gcd;
		}
	}
}

void showFractions(int arr[])
{
	//Holds user response to "Press any key to continue"
	char x;

	//Starts formatting the fraction table
	cout << "Your two fractions were " << arr[0] << "/" << arr[1] << " and " << arr[2] << "/" << arr[3] << endl;
	cout << left << setw(15) << "Mutli" << left << setw(15) << "Div" << left << setw(15) << "Add" << left << setw(15) << "Sub" << endl;
	cout << left << setw(15) << "*" << left << setw(15) << "/" << left << setw(15) << "+" << left << setw(15) << "-" << endl;

	//Reduce fractions 2/2 to 1 whole, if not it will output fractions as number/number, ie 1/3
	for (int i = 4; i < 12; i = i + 2)
	{
		if (arr[i] == arr[i + 1]){
			cout << left << setw(15) << 1;
		}
		else{
			cout << arr[i] << "/" << left << setw(15) << arr[i + 1];
		}
	}
	cout << endl << endl << "Press any key to continue" << endl;
	cin >> x;
}

void readFile(string arrS[], int arr[][100]){
	ifstream inputFile;
	int numStud;
	int numTest;

	inputFile.open("grades.txt");

	if (inputFile){
		//Get Number of Students
		inputFile >> numStud;

		//Get Number of Tests
		inputFile >> numTest;

		//Get repeating student data
		for (int n = 0; n < numStud; n++){

			//Get student name
			inputFile >> arrS[n];
			//Get student marks
			for (int m = 0; m < numTest; m++){
				inputFile >> arr[n][m];
			}
		}
		inputFile.close();
	}
	else{
		cout << "Error reading the file" << endl;
	}
}

void calculateAverage(string arrS[], int arr[][100], float stuAvg[]){
	float avg;
	int sum;

	//calculate average test scores for each student
	for (int i = 0; i < 10; i++){
		sum = 0;
		for (int ii = 0; ii < 5; ii++){
			sum = sum + arr[i][ii];
		}
		stuAvg[i] = float(sum) / 5;
	}

}
char calculateGrade(float stuAvg){	
		if (stuAvg < 50){
			return 'F';
		}
		else if (stuAvg < 60){
			return 'E';
		}
		else if (stuAvg < 70){
			return 'D';
		}
		else if (stuAvg < 80){
			return 'C';
		}
		else if (stuAvg < 90){
			return 'B';
		}
		else if (stuAvg <= 100){
			return 'A';
		}
}

void calculateTestAverage(int testScore[][100], float testAvg[]){

	for (int i = 0; i < 5; i++){
		float numStu = 10;
		int sum = 0;

		for (int t = 0; t < 10; t++){
			sum = sum + testScore[t][i];
		}
		testAvg[i] = sum / numStu;
	}
}
void printGrades(string nameStu[], int testScore[][100], float stuAvg[], char stuGrade[], float testAvg[]){
	float avgAvg = 0;
	float sum = 0;
	cout << setw(10) << "Name" << setw(7) << "test1" << setw(7) << "test2" << setw(7) << "test3" << setw(7) << "test4" << setw(7) << "test5" << setw(7) << "AVG" << setw(7) << "Grade" << endl << endl;

	//Hardcoded beware
	for (int q = 0; q < 10; q++){
		cout << setw(10) << nameStu[q];
		for (int r = 0; r < 5; r++){
			cout << setw(7) << testScore[q][r];
		}
		cout << setw(7) << stuAvg[q] << setw(7) << stuGrade[q] << endl;
	}

	cout << setw(10) << "test avg";
	for (int i = 0; i < 5; i++){
		cout << setw(7) << testAvg[i];
	}
	for (int t = 0; t < 5; t++){
		sum = sum + testAvg[t];
	}
	avgAvg = sum / 5;
	cout << setw(7) << avgAvg << endl;
}