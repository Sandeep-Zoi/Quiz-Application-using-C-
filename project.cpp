#include <iostream>
#include <vector>
using namespace std;

// Question Class
class Question {
private:
    string question;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;

public:
    // Constructor
    Question(string q, string a, string b, string c, string d, char correct) {
        question = q;
        optionA = a;
        optionB = b;
        optionC = c;
        optionD = d;
        correctAnswer = correct;
    }

    // Display Question
    void displayQuestion() {
        cout << "\n" << question << endl;
        cout << "A. " << optionA << endl;
        cout << "B. " << optionB << endl;
        cout << "C. " << optionC << endl;
        cout << "D. " << optionD << endl;
    }

    // Check Answer
    bool checkAnswer(char userAnswer) {
        return (toupper(userAnswer) == correctAnswer);
    }
};

// Quiz Class
class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() {
        score = 0;
    }

    // Add question to quiz
    void addQuestion(Question q) {
        questions.push_back(q);
    }

    // Start quiz
    void start() {
        char userAns;

        cout << "\n===== QUIZ STARTED =====\n";

        for (int i = 0; i < questions.size(); i++) {
            questions[i].displayQuestion();
            cout << "Enter your answer (A/B/C/D): ";
            cin >> userAns;

            if (questions[i].checkAnswer(userAns)) {
                cout << "? Correct!\n";
                score++;
            } else {
                cout << "? Wrong!\n";
            }
        }

        cout << "\n===== QUIZ FINISHED =====";
        cout << "\nYour Score: " << score << " / " << questions.size() << endl;
    }
};

int main() {
    Quiz quiz;

    // Adding questions using objects
    quiz.addQuestion(Question(
        "1. Who is the father of C++?",
        "Dennis Ritchie", "James Gosling", "Bjarne Stroustrup", "Guido van Rossum",
        'C'
    ));

    quiz.addQuestion(Question(
        "2. Which of the following is an OOP concept?",
        "Polymorphism", "Recursion", "Pointer", "Array",
        'A'
    ));

    quiz.addQuestion(Question(
        "3. What does OOP stand for?",
        "Object-Oriented Programming", "Original Output Process", 
        "Open Operational Protocol", "Open Object Program",
        'A'
    ));

    // Start the quiz
    quiz.start();

    return 0;
}
