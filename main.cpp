#include "printer.h"
#include "increment.h"

std::vector<int> test_arr = {1,2,3,4,5};

std::ostream & operator << (std::ostream &os, const std::vector<int> &arr) {
    for (auto num : arr )
        os << num << " " ;
    os << std::endl;

    return os;
}

void functor_test() {
    static int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int to_add = 5;

    std::transform(arr, arr+n, arr, Increment(to_add));

    for (int i=0; i<n; i++)
        std::cout << arr[i] << " ";

    std::cout << '\n';
}
void functor_test1(std::vector<int> &arr, const int to_add=5) {
    std::transform(arr.begin(), arr.end(), arr.begin(), Increment(to_add));
    std::cout << "\nElements after increment of " << to_add << ":" << '\n' << arr;
}

/**
 * To implement a repeating timer using asio you need to change the timer's expiry time in your callback function,
 * and to then start a new asynchronous wait. Obviously this means that the callback function will need to be able
 * to access the timer object. To this end we add two new parameters to the print function:
 * A pointer to a timer object.
 * A counter so that we can stop the program when the timer fires for the sixth time.
 */

void print(const asio::error_code & /*e*/,
    asio::deadline_timer *t, int *count)
{
    std::cout << "Hello World" << std::endl;
    if(*count < 5) {
        std::cout << *count << std::endl;
        ++(*count);
        functor_test1(test_arr,*count);
        /*
         * Next we move the expiry time for the timer along by one second from the previous expiry time.
         * By calculating the new expiry time relative to the old, we can ensure that the timer does not
         * drift away from the whole-second mark due to any delays in processing the handler.
         */
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(boost::bind(print,
        asio::placeholders::error, t, count));
    }
}

void asyncio_test_global_function() {
    asio::io_service io;
    int count  = 0;
    asio::deadline_timer t(io, boost::posix_time::seconds(1));
    t.async_wait(boost::bind(print,
                             asio::placeholders::error, &t, &count));

    io.run();

    std::cout << "Final count is " << count << std::endl;
}

int main()
{
    asio::io_service io;
    //asyncio_test_global_function();

    Printer printer(io);
    io.run();

    return 0;
}
