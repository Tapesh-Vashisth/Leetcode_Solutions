#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;


class node{
    string name;
    list <string> neighbours;

    public:
        string getname(){
            return name;
        }

        void setname(string name){
            this->name = name;
        }

        void addneighbours(string n){
            this->neighbours.push_back(n);
            this->neighbours.sort();
        }

        list <string> getneighbours(){
            return neighbours;
        }

        node(string name){
            this->name = name;
        }
};

class cityGraph{
    unordered_map <string, node *> m;
    int num_paths;
    public:
        cityGraph(unordered_set <string> cities, int paths){
            for (auto city: cities){
                m[city] = new node(city);
            }
            num_paths = paths;
        }

        void addEdge(string x, string y, bool undir = false){
            m[x]->addneighbours(y);
            if (undir){
                m[y]->addneighbours(x);
            }
        }

        void print(){
            auto it = m.begin();
            for (; it != m.end(); it++){
                cout << (*it).first << "--->";
                for (auto hold: ((*it).second->getneighbours())){             
                    cout << hold << " "; 
                }
                cout << endl;
            }
        }

        bool checker(list <string> findin, string val){
            for (auto hold: findin){
                if (hold == val){
                    return true;
                }
            }

            return false;
        }

        bool itineraryHelper(string cur, unordered_map<string, vector<bool>>& done, vector <string>& construct, int counter){
            if (counter == num_paths){
                construct.push_back(cur);
                return true;
            }

            bool decider = false;
            int index = 0;
            for (auto hold: m[cur]->getneighbours()){
                if (done[cur][index] != false){
                    done[cur][index] = true;
                    bool temp = itineraryHelper(hold, done, construct, counter + 1);
                    done[cur][index] = false;
                    if (temp == true){
                        decider = true;
                        break;
                    }
                }
                index++;
            }

            if (decider == true){
                construct.push_back(cur);
                return true;
            }

            return false;
        }

        vector <string> itinerary(string start){
            unordered_map<string, vector <bool>> done;
            for (auto hold: m){
                done[hold.first] = vector <bool> (hold.second->getneighbours().size(), false);
            }

            vector <string> ans;
            itineraryHelper(start, done, ans, 0);
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

vector<string> findItinerary(vector<vector<string>>& tickets){
    unordered_set <string> cities;
    for (int i = 0; i < tickets.size(); i++){
        cities.insert(tickets[i][0]);
        cities.insert(tickets[i][1]);
    }

    cityGraph cg(cities, tickets.size());

    for (int i = 0; i < tickets.size(); i++){
        cg.addEdge(tickets[i][0], tickets[i][1], false);
    }

    cg.print();

    return cg.itinerary("JFK");
}

int main(){
    vector <vector <string>> test = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector <string> ans = findItinerary(test);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}