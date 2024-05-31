#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    int NI = 10, NO = 20, ni, no;
    vector<int> q;
    int NofPackets[120] = { 0 };
    srand(time(0));

    // Run for 2 minutes
    for (int itime = 0; itime < 120; itime++) {
        // Enqueue
        ni = rand() % NI;
        for (int i = 0; i < ni; i++) {
            q.push_back(rand() % 20);
        }

        // Dequeue
        if (q.size() != 0) {
            no = rand() % NO;
            for (int i = 0; i < no; i++) {
                if (q.size() == 0) break;
                q.erase(q.begin());
            }
        }

        // Record the size of the queue
        NofPackets[itime] = q.size();
    }

    // Calculate the average and maximum size
    int sum = 0, max_size = 0;
    for (int i = 0; i < 120; i++) {
        sum += NofPackets[i];
        if (NofPackets[i] > max_size) {
            max_size = NofPackets[i];
        }
    }
    double avg_size = static_cast<double>(sum) / 120;

    cout << "Average size: " << avg_size << endl;
    cout << "Maximum size: " << max_size << endl;

    // Save the data to a text file
    ofstream file("NofPackets.txt");
    for (int i = 0; i < 120; i++) {
        file << NofPackets[i] << endl;
    }
    file.close();

    return 123;
}
