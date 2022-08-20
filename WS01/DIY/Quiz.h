#ifndef quizzer_QUIZ_H
#define quizzer_QUIZ_H
#include <cstdlib>
namespace quizzer{
    struct Answer{
        char answer[
            150];
    };
    struct Quiz{
        char question[20][1024];
        struct Answer answer;
        int qType[20]; // if 1 it's MA if 0 it's MC
    };
/// <summary>
/// Loads a quiz from a file.  If a quiz is already loaded, that quiz is discarded
///   (together with any information regarding that previously loaded quiz).
/// </summary>
/// <param name="filename">The name of the file containing the quiz.</param>
/// <returns>0 if the quiz was loaded, any other value if some error appeared
///   (null parameter, empty parameter, missing file).</returns>
int LoadQuiz(const char* filename);

/// <summary>
/// Checks if a quiz is currently loaded and is valid.
///   A quiz is considered valid if it has at least 5 questions
///   and each question is correct (multiple-choice questions have
///   exactly one correct answer, and multiple-answer questions
///   have at least one correct answer.
///   
///   For each question in the quiz, print to screen "Question X -> OK" or
///   "Question X -> ERROR" if the question is valid or it contains some error.
/// 
///   If the quiz has an insufficient number of questions, this function prints nothing.
/// </summary>
/// <returns>1 if the quiz is loaded and correct, 0 otherwise</returns>
#define MAX_QUESTIONS 5

struct Question
{
    string QuestionText; // Actual question text.
    char choices[];    // Array of answers from which user can choose.
    int Answer;          // Index of correct answer within Choices.
};

int IsQuizValid();

/// <summary>
/// Checks if there are still questions in the quiz that haven't been shown to the user.
/// </summary>
/// <returns>1 if the quiz has more questions to show to the user; 0 otherwise.</returns>
int HasMoreQuestions();

/// <summary>
/// Prints to the screen the next question from the quiz and records
///   user's answer. Once this function is called at least once,
///   it is considered that the user took the quiz.
/// 
/// After the question is shown, this function will print "Your answer? "
///   and read the user's choice.
/// </summary>
void ShowNextQuestion();

/// <summary>
/// Prints to the screen the results in the format
///   "QUIZ RESULTS: your score is X/Y.".
/// 
/// If the user didn't took the quiz, this function does nothing.
/// </summary>
void ShowQuizResults();
}
#endif