#include <iostream>
#include <fstream>
#include <math.h>
// #include <time.h>

#define PATH_STR "./path.txt"

using namespace std;

typedef struct Objects
{
    int x;
    int y;

} object_t;

object_t initialization(object_t Object) {
    Object.x = 0;
    Object.y = 0;

    return Object;
}

object_t move(object_t Object, int x, int y) {

    int next_x = Object.x + x;
    int next_y = Object.y + y;
    if ((next_x <= 500 && next_x >= -500) && (next_y <= 500 && next_y >= -500)) {
        Object.x = next_x;
        Object.y = next_y;
    }


    return Object; 
}


int random_num() {

    int number = rand() % 2;

    int sign_num = 1 + rand() % 10;
    int sign = (sign_num % 2 == 0) ? 1 : -1;
    number *= sign;

    return number;
}

void write_path(object_t Object) {

    ofstream file_out;
    file_out.open(PATH_STR, ios::app);
    if (file_out.is_open()) {
        file_out << "(" << Object.x  << ", " << Object.y << ")" << endl;
    }

}

void clean_file() {
    ofstream file_out;
    file_out.open(PATH_STR);
    if (file_out.is_open()) {
        file_out << "";
    }
}


double find_distance(int my_x, int my_y, int dest_x, int dest_y) {
    int katet_1 = abs(dest_x - my_x);
    int katet_2 = abs(dest_y - my_y);

    double distance = sqrt(pow(katet_1, 2) + pow(katet_2, 2));

    return distance;
}

int main() {

    object_t Object;
    Object = initialization(Object);

    clean_file();

    int cnt1 = 10;

    
    srand(time(NULL));
    for (int i = 0; i < cnt1; i++)
    {
        int step_x = 0;
        int step_y = 0;
        
        while (step_x == 0 && step_y == 0) {
            step_x = random_num();
            step_y = random_num();
        }

        Object = move(Object, step_x, step_y);
        
        write_path(Object);
        // cout << "x: " << step_x << "\n" << "y: " << step_y << endl;
    }

    int distance_x = 0, distance_y = 0;
    double distance = find_distance(Object.x, Object.y, distance_x, distance_y);

    cout << "(" << Object.x << ", " << Object.y << ")" << "-->" << "(" << distance_x << ", " << distance_y << ")" << " : " << distance << endl; 
    return 0;
}
