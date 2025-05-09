#include "high_scores.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

int32_t latest(const int32_t *scores, size_t scores_len){
    if ((scores != NULL) && (scores_len > 0)) return scores[scores_len - 1];
    else return EIO;

}

int32_t personal_best(const int32_t *scores, size_t scores_len){

    if ((scores != NULL) && (scores_len > 0)){
        int32_t max_number = scores[0];
        for (size_t i = 0; i < scores_len; i++){
            if (max_number < scores[i]){
                max_number = scores[i];
            }
        }
        return max_number;
    }
     else return EIO;

}
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    int32_t cpy_output[scores_len];
    int32_t buffer = 0;
    if ((scores != NULL) && (scores_len != 0) && (output != NULL)){
        memcpy(cpy_output, scores, scores_len * sizeof(int32_t) );

        for (size_t i = 0; i < scores_len; i++){
            for (size_t j = 0; j < scores_len -1 -i; j++){
                if (cpy_output[j] < cpy_output[j+1]){
                    buffer = cpy_output[j];
                    cpy_output[j] = cpy_output[j+1];
                    cpy_output[j+1] = buffer;
                }
            }
        }
    }
     else return EIO;
    size_t top_count = scores_len < 3 ? scores_len : 3;
    for (size_t k = 0; k < top_count; k++){
        output[k] = cpy_output[k];
    }
    return top_count;

}
