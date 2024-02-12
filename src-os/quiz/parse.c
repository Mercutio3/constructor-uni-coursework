#include <stdio.h>
#include <string.h>
#include <time.h>
#include <jansson.h>
#include "quiz.h"

extern int parse(quiz_t *quiz, char *msg){
    //Initialize json variables
    const char *json_string = msg;
    json_t *root;
    json_error_t error;

    //Catch and handle errors loading json string
    root = json_loads(json_string, 0, &error);
    if(!root){
        perror("Root error.");
        return -1;
    }

    json_t *results = json_object_get(root, "results");
    if(json_is_array(results)){
        size_t array_size = json_array_size(results);
        
        //Update quiz data structure's n and max
        quiz->n++;
        quiz->max = 8*quiz->n;

        for(size_t i = 0; i < array_size; i++){
            json_t *resultItem = json_array_get(results, i);

            //Get question and correct answer from JSON string
            const char *question = json_string_value(json_object_get(resultItem, "question"));
            const char *correct_answer = json_string_value(json_object_get(resultItem, "correct_answer"));

            //Update quiz data structure's question and answer
            quiz->question = question;
            quiz->answer = correct_answer;
            quiz->choices[0] = correct_answer; //Correct answer initially kept in [0]

            //Get incorrect answers from JSON string
            json_t *incorrect_answers = json_object_get(resultItem, "incorrect_answers");
            if(json_is_array(incorrect_answers)){
                size_t incorrect_answers_size = json_array_size(incorrect_answers);
                
                //Add incorrect answers to quiz data structure's choices
                for(size_t j = 0; j < incorrect_answers_size; j++){
                    const char *incorrect_answer = json_string_value(json_array_get(incorrect_answers, j));
                    quiz->choices[j+1] = incorrect_answer;
                }
            }
            
        }

        //Shuffle quiz data structure's choices[] array
        srand(time(0));
        for(int i = 3; i > 0; i--){
            int j = rand() % (i + 1);
            const char *temp = quiz->choices[i];
            quiz->choices[i] = quiz->choices[j];
            quiz->choices[j] = temp;
        }
    }

    return 0;
}