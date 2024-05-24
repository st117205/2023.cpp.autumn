#include<SDL.h>
#include<iostream>
#include<limits>
#include<time.h>
#include<string>

bool init();
void close();
void visualize(int x, int y, int z);
void heapSort(int* input, int n);
int partition_array(int a[], int si, int ei);
void quickSort(int a[], int si, int ei);
void merge2SortedArrays(int a[], int si, int ei);
void mergeSort(int a[], int si, int ei);
void loadArr();
void randomizeAndSaveArray();
void execute();
bool controls();
void intro();

int SCREEN_WIDTH = 910;
int SCREEN_HEIGHT = 750;

int arrSize = 130;
int rectSize = 15;

int* arr = new int[arrSize] { 0 };
int* carr = new int[arrSize] { 0 };

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool complete = false;

int main(int argc, char* argv[])
{
    setlocale(0, "rus");
    intro();

    while (1)
    {
        std::cout << '\n';
        if (controls())
        {
            execute();
        }
        else
        {
            std::cout << "\nВыход из программы\n";
            break;
        }
    }

    return 0;
}

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Couldn't initialize SDL. SDL_Error: " << SDL_GetError();
        success = false;
    }
    else
    {
        if (!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")))
        {
            std::cout << "Warning: Linear Texture Filtering not enabled.\n";
        }

        window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Couldn't create window. SDL_Error: " << SDL_GetError();
            success = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL)
            {
                std::cout << "Couldn't create renderer. SDL_Error: " << SDL_GetError();
                success = false;
            }
        }
    }

    return success;
}

void close()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

void visualize(int x = -1, int y = -1, int z = -1)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    int j = 0;
    for (int i = 0; i <= SCREEN_WIDTH - rectSize; i += rectSize)
    {
        SDL_PumpEvents();

        SDL_Rect rect = { i, 0, rectSize, arr[j] };
        if (complete)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        else if (j == x || j == z)
        {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if (j == y)
        {
            SDL_SetRenderDrawColor(renderer, 165, 105, 189, 0);
            SDL_RenderFillRect(renderer, &rect);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 170, 183, 184, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        j++;
    }
    SDL_RenderPresent(renderer);
}

void heapSort(int* input, int n)
{
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;

        while (childIndex > 0)
        {
            if (input[childIndex] > input[parentIndex])
            {
                int temp = input[parentIndex];
                input[parentIndex] = input[childIndex];
                input[childIndex] = temp;

            }
            else
            {
                break;
            }

            visualize(parentIndex, childIndex);
            SDL_Delay(40);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    for (int heapLast = n - 1; heapLast >= 0; heapLast--)
    {
        int temp = input[0];
        input[0] = input[heapLast];
        input[heapLast] = temp;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < heapLast)
        {
            int maxIndex = parentIndex;

            if (input[leftChildIndex] > input[maxIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex<heapLast && input[rightChildIndex]>input[maxIndex])
            {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex)
            {
                break;
            }

            int temp = input[parentIndex];
            input[parentIndex] = input[maxIndex];
            input[maxIndex] = temp;

            visualize(maxIndex, parentIndex, heapLast);
            SDL_Delay(40);

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

int partition_array(int a[], int si, int ei)
{
    int count_small = 0;

    for (int i = (si + 1); i <= ei; i++)
    {
        if (a[i] <= a[si])
        {
            count_small++;
        }
    }
    int c = si + count_small;
    int temp = a[c];
    a[c] = a[si];
    a[si] = temp;
    visualize(c, si);

    int i = si, j = ei;

    while (i<c && j>c)
    {
        if (a[i] <= a[c])
        {
            i++;
        }
        else if (a[j] > a[c])
        {
            j--;
        }
        else
        {
            int temp_1 = a[j];
            a[j] = a[i];
            a[i] = temp_1;

            visualize(i, j);
            SDL_Delay(70);

            i++;
            j--;
        }
    }
    return c;
}

void quickSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int c = partition_array(a, si, ei);
    quickSort(a, si, c - 1);
    quickSort(a, c + 1, ei);

}

void merge2SortedArrays(int a[], int si, int ei)
{
    int size_output = (ei - si) + 1;
    int* output = new int[size_output];

    int mid = (si + ei) / 2;
    int i = si, j = mid + 1, k = 0;
    while (i <= mid && j <= ei)
    {
        if (a[i] <= a[j])
        {
            output[k] = a[i];
            visualize(i, j);
            i++;
            k++;
        }
        else
        {
            output[k] = a[j];
            visualize(i, j);
            j++;
            k++;
        }

    }
    while (i <= mid)
    {
        output[k] = a[i];
        visualize(-1, i);
        i++;
        k++;
    }
    while (j <= ei)
    {
        output[k] = a[j];
        visualize(-1, j);
        j++;
        k++;
    }
    int x = 0;
    for (int l = si; l <= ei; l++)
    {
        a[l] = output[x];
        visualize(l);
        SDL_Delay(15);
        x++;
    }
    delete[]output;
}

void mergeSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;

    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);

    merge2SortedArrays(a, si, ei);
}

void loadArr()
{
    memcpy(arr, carr, sizeof(int) * arrSize);
}

void randomizeAndSaveArray()
{
    unsigned int seed = (unsigned)time(NULL);
    srand(seed);
    for (int i = 0; i < arrSize; i++)
    {
        int random = rand() % (SCREEN_HEIGHT);
        carr[i] = random;
    }
}

void execute()
{
    if (!init())
    {
        std::cout << "Не удалось инициализировать.\n";
    }
    else
    {
        randomizeAndSaveArray();
        loadArr();
        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                    complete = false;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case(SDLK_q):
                        quit = true;
                        complete = false;
                        std::cout << "\nВы вышли из визуализатора.\n";
                        break;
                    case(SDLK_0):
                        randomizeAndSaveArray();
                        complete = false;
                        loadArr();
                        std::cout << "\nНовый массив сгенерирован.\n";
                        break;
                    case(SDLK_2):
                        loadArr();
                        std::cout << "\nСортировка MergeSort запущена.\n";
                        complete = false;
                        mergeSort(arr, 0, arrSize - 1);
                        complete = true;
                        std::cout << "\n.Сортировка MergeSort завершена\n";
                        break;
                    case(SDLK_1):
                        loadArr();
                        std::cout << "\nСортировка QuickSort запущена.\n";
                        complete = false;
                        quickSort(arr, 0, arrSize - 1);
                        complete = true;
                        std::cout << "\nСортировка QuickSort завершена.\n";
                        break;
                    case(SDLK_3):
                        loadArr();
                        std::cout << "\nСортировка HeapSort запущена.\n";
                        complete = false;
                        heapSort(arr, arrSize);
                        complete = true;
                        std::cout << "\nСортировка HeapSort завершена.\n";
                        break;
                    }
                }
            }
            visualize();
        }
        close();
    }
}

bool controls()
{
    std::cout << "Доступные опции работы с массивом:-\n";
    std::cout << "Введите 0 для генерации нового массива.\n";
    std::cout << "Введите 1 для визуализации алгоритма QuickSort.\n";
    std::cout << "Введите 2 для визуализации алгоритма MergeSort.\n";
    std::cout << "Введите 3 для визуализации алгоритма HeapSort.\n";
    std::cout << "Нажмите q для выхода из визуализатора\n";
    std::cout << "Нажмите Enter для запуска визуализатора или введите -1 и нажмите Enter для выхода из программы\n\n";


    std::string s;
    std::getline(std::cin, s);
    if (s == "-1")
    {
        return false;
    }
    return true;
}

void intro()
{
    std::string s;
    std::getline(std::cin, s);
    if (s == "\n")
    {
        return;
    }
}