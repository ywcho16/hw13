#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Queue {
public:
    int NI, NO, capacity;
    vector<int> buffer;
    int totalPackets, lostPackets, maxQueueSize;

    Queue(int ni, int no, int cap) : NI(ni), NO(no), capacity(cap), totalPackets(0), lostPackets(0), maxQueueSize(0) {
        buffer.reserve(capacity);
    }

    void simulate() {
        for (int seconds = 0; seconds < 120; ++seconds) {
            int ni = rand() % NI;
            int no = rand() % NO;

            for (int i = 0; i < ni; ++i) {
                if (buffer.size() < capacity) {
                    buffer.push_back(rand() % 100);
                    totalPackets++;
                }
                else {
                    lostPackets++;
                }
            }

            for (int i = 0; i < no; ++i) {
                if (!buffer.empty()) {
                    buffer.erase(buffer.begin());
                }
            }

            maxQueueSize = max(maxQueueSize, (int)buffer.size());
        }
    }

    float getQueueFullness() {
        return ((float)maxQueueSize / capacity) * 100;
    }

    float getPacketLossRate() {
        return ((float)lostPackets / totalPackets) * 100;
    }
};

int main() {
    srand((unsigned)time(0));

    // ¿¹½Ã: NI = 10, NO = 15, capacity = 100
    Queue queue(10, 15, 100);
    queue.simulate();

    cout << "Queue Fullness: " << queue.getQueueFullness() << "%" << endl;
    cout << "Packet Loss Rate: " << queue.getPacketLossRate() << "%" << endl;

    return 0;
}
