#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Для exp()
#include <time.h>   // Для time() и srand()

// --- Гиперпараметры ---
#define NUM_INPUTS 2    // Количество входных нейронов
#define NUM_HIDDEN 2    // Количество нейронов в скрытом слое
#define NUM_OUTPUTS 1   // Количество выходных нейронов
#define LEARNING_RATE 0.1 // Скорость обучения
#define EPOCHS 1000000    // Количество эпох обучения

// --- Функции активации ---

// Сигмоида
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Производная сигмоиды (используется в обратном распространении)
double sigmoid_derivative(double x) {
    return x * (1.0 - x); // x здесь - это уже активированное значение (sigmoid(sum))
}

// --- Структура для нейронной сети ---
typedef struct {
    // Веса между входным и скрытым слоем (NUM_INPUTS x NUM_HIDDEN)
    double weights_ih[NUM_INPUTS][NUM_HIDDEN];
    // Смещения скрытого слоя (NUM_HIDDEN)
    double bias_h[NUM_HIDDEN];

    // Веса между скрытым и выходным слоем (NUM_HIDDEN x NUM_OUTPUTS)
    double weights_ho[NUM_HIDDEN][NUM_OUTPUTS];
    // Смещения выходного слоя (NUM_OUTPUTS)
    double bias_o[NUM_OUTPUTS];

    // Активации (выходы) нейронов
    double hidden_activations[NUM_HIDDEN];
    double output_activation;

} NeuralNetwork;

// --- Инициализация нейронной сети ---
void initialize_network(NeuralNetwork *nn) {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    // Инициализация весов и смещений случайными значениями
    // Веса обычно инициализируют малыми случайными значениями,
    // чтобы избежать насыщения сигмоиды на ранних этапах.
    for (int i = 0; i < NUM_INPUTS; i++) {
        for (int j = 0; j < NUM_HIDDEN; j++) {
            nn->weights_ih[i][j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0; // от -1.0 до 1.0
        }
    }
    for (int i = 0; i < NUM_HIDDEN; i++) {
        nn->bias_h[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }

    for (int i = 0; i < NUM_HIDDEN; i++) {
        for (int j = 0; j < NUM_OUTPUTS; j++) {
            nn->weights_ho[i][j] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        nn->bias_o[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}

// --- Прямое распространение (Forward Pass) ---
double forward_pass(NeuralNetwork *nn, double inputs[NUM_INPUTS]) {
    // 1. Вычисление активаций скрытого слоя
    for (int j = 0; j < NUM_HIDDEN; j++) {
        double sum_hidden = 0.0;
        for (int i = 0; i < NUM_INPUTS; i++) {
            sum_hidden += inputs[i] * nn->weights_ih[i][j];
        }
        sum_hidden += nn->bias_h[j];
        nn->hidden_activations[j] = sigmoid(sum_hidden);
    }

    // 2. Вычисление активации выходного слоя
    double sum_output = 0.0;
    for (int j = 0; j < NUM_HIDDEN; j++) {
        sum_output += nn->hidden_activations[j] * nn->weights_ho[j][0]; // Только 1 выход
    }
    sum_output += nn->bias_o[0]; // Только 1 смещение выхода
    nn->output_activation = sigmoid(sum_output);

    return nn->output_activation;
}

// --- Обучение сети (Backpropagation) ---
void train_network(NeuralNetwork *nn, double inputs[NUM_INPUTS], double target) {
    // 1. Прямое распространение (сохраняем промежуточные активации)
    double predicted_output = forward_pass(nn, inputs);

    // 2. Вычисление ошибки выходного слоя
    double output_error = target - predicted_output;
    double output_delta = output_error * sigmoid_derivative(predicted_output);

    // 3. Вычисление ошибок скрытого слоя (распространяем ошибку назад)
    double hidden_errors[NUM_HIDDEN];
    double hidden_deltas[NUM_HIDDEN];

    for (int i = 0; i < NUM_HIDDEN; i++) {
        // Ошибка скрытого нейрона - это сумма (ошибка_выхода * вес_от_скрытого_к_выходу)
        hidden_errors[i] = output_delta * nn->weights_ho[i][0]; 
        hidden_deltas[i] = hidden_errors[i] * sigmoid_derivative(nn->hidden_activations[i]);
    }

    // 4. Обновление весов и смещений между скрытым и выходным слоем
    for (int i = 0; i < NUM_HIDDEN; i++) {
        nn->weights_ho[i][0] += LEARNING_RATE * output_delta * nn->hidden_activations[i];
    }
    nn->bias_o[0] += LEARNING_RATE * output_delta;

    // 5. Обновление весов и смещений между входным и скрытым слоем
    for (int i = 0; i < NUM_INPUTS; i++) {
        for (int j = 0; j < NUM_HIDDEN; j++) {
            nn->weights_ih[i][j] += LEARNING_RATE * hidden_deltas[j] * inputs[i];
        }
    }
    for (int i = 0; i < NUM_HIDDEN; i++) {
        nn->bias_h[i] += LEARNING_RATE * hidden_deltas[i];
    }
}

int main() {
    NeuralNetwork nn;
    initialize_network(&nn);

    // Тренировочные данные для XOR
    // Входы
    double training_inputs[4][NUM_INPUTS] = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0},
        {1.0, 1.0}
    };
    // Целевые выходы
    double training_targets[4] = {0.0, 0.0, 0.0, 1.0};

    printf("Training NN\n");

    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        double total_epoch_error = 0.0;
        for (int i = 0; i < 4; i++) {
            train_network(&nn, training_inputs[i], training_targets[i]);
            double predicted = forward_pass(&nn, training_inputs[i]);
            total_epoch_error += fabs(training_targets[i] - predicted); // Суммируем абсолютную ошибку
        }

        if (epoch % 1000 == 0) { // Печатаем прогресс каждые 1000 эпох
            printf("epoch %d, error: %.6f\n", epoch, total_epoch_error / 4.0);
        }
        // Условие остановки: если ошибка достаточно мала
        if (total_epoch_error / 4.0 < 0.01 && epoch > 1000) { 
            printf("Learning complete(error insagnificant) at epoch %d\n", epoch);
            break;
        }
    }
    printf("Learning Complete\n");

    printf("\nChecking NN\n");
    for (int i = 0; i < 4; i++) {
        double prediction = forward_pass(&nn, training_inputs[i]);
        // Для бинарной классификации, обычно округляют до ближайшего целого
        int rounded_prediction = (prediction >= 0.5) ? 1 : 0; 
        printf("Enter: (%.0f, %.0f) -> Predict: %.4f (round: %d), Excepted: %.0f\n", training_inputs[i][0], training_inputs[i][1], prediction, rounded_prediction, training_targets[i]);
    }
    
    // Опционально: вывести итоговые веса
    /*
    printf("\nИтоговые веса и смещения:\n");
    printf("Weights IH:\n");
    for(int i=0; i<NUM_INPUTS; ++i) {
        for(int j=0; j<NUM_HIDDEN; ++j) {
            printf("  w_ih[%d][%d]=%.4f ", i, j, nn.weights_ih[i][j]);
        }
        printf("\n");
    }
    printf("Bias H:\n");
    for(int i=0; i<NUM_HIDDEN; ++i) {
        printf("  b_h[%d]=%.4f ", i, nn.bias_h[i]);
    }
    printf("\n");
    printf("Weights HO:\n");
    for(int i=0; i<NUM_HIDDEN; ++i) {
        printf("  w_ho[%d][0]=%.4f ", i, nn.weights_ho[i][0]);
    }
    printf("\n");
    printf("Bias O:\n");
    printf("  b_o[0]=%.4f\n", nn.bias_o[0]);
    */

    return 0;
}