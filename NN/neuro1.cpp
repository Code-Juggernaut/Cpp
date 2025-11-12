#include <stdio.h>
#include <stdlib.h> // Для rand() и srand()
#include <time.h>   // Для time()

// Определение структуры для нашего перцептрона
typedef struct {
    double weights[2]; // Веса для двух входов
    double bias;       // Смещение
    double learningRate; // Скорость обучения
} Perceptron;

// --- Функция активации (пороговая функция) ---
// Если сумма больше или равна порогу, возвращаем 1, иначе 0
int activate(double sum) {
    return (sum >= 0.0) ? 1 : 0; // Порог в данном случае 0.0
}

// --- Инициализация перцептрона ---
void initializePerceptron(Perceptron *p, double lr) {
    // Инициализируем генератор случайных чисел
    srand(time(NULL)); 
    
    // Инициализируем веса и смещение случайными значениями от -1.0 до 1.0
    p->weights[0] = 0;
    p->weights[1] = 0;
    p->bias = 0;
    
    p->learningRate = lr;
}

// --- Функция для предсказания выхода нейросети ---
int predict(const Perceptron *p, int input1, int input2) {
    double sum = input1 * p->weights[0] + input2 * p->weights[1] + p->bias;
    return activate(sum);
}

// --- Функция обучения перцептрона ---
void train(Perceptron *p, int inputs[][2], int targets[], int num_samples, int epochs) {
    printf("Start learning...\n");
    for (int epoch = 0; epoch < epochs; epoch++) {
        int total_error = 0; // Для отслеживания ошибок в текущей эпохе
        for (int i = 0; i < num_samples; i++) {
            int input1 = inputs[i][0];
            int input2 = inputs[i][1];
            int target = targets[i]; // Правильный ответ

            int prediction = predict(p, input1, input2); // Предсказание нейросети

            int error = target - prediction; // Расчет ошибки

            // Если есть ошибка, корректируем веса и смещение
            if (error != 0) {
                total_error += abs(error); // Увеличиваем общий счетчик ошибок

                p->weights[0] += p->learningRate * error * input1;
                p->weights[1] += p->learningRate * error * input2;
                p->bias += p->learningRate * error;
            }
        }
        printf("epoch %d: total error = %d\n", epoch + 1, total_error);
        // Если ошибок нет, можно досрочно прекратить обучение
        if (total_error == 0) {
            printf("Learning end, no error.\n");
            break;
        }
    }
    printf("learning end.\n");
}

int main() {
    Perceptron myPerceptron;
    initializePerceptron(&myPerceptron, 0.1); // Скорость обучения 0.1

    // Тренировочные данные для логической функции И (AND)
    // Входы
    int training_inputs[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    // Целевые выходы (правильные ответы)
    int training_targets[4] = {0, 1, 1, 0};

    int num_samples = 4; // Количество тренировочных примеров
    int epochs = 100;    // Количество эпох обучения

    // Обучаем перцептрон
    train(&myPerceptron, training_inputs, training_targets, num_samples, epochs);

    printf("\nChecking NN:\n");
    // Проверяем работу нейросети на тех же данных
    for (int i = 0; i < num_samples; i++) {
        int input1 = training_inputs[i][0];
        int input2 = training_inputs[i][1];
        int prediction = predict(&myPerceptron, input1, input2);
        printf("enter: (%d, %d) -> predict: %d (real result: %d)\n", input1, input2, prediction, training_targets[i]);
    }

    printf("\ntotal weights: w1=%.4f, w2=%.4f, bias=%.4f\n", myPerceptron.weights[0], myPerceptron.weights[1], myPerceptron.bias);

    return 0;
}