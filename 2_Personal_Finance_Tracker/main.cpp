#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <list>
#include <map>

using namespace std;


#define INPUT_TRANS     ((int)(1))
#define VIEW_TRANS      ((int)(2))
#define VIEW_SUMMARY    ((int)(3))
#define GET_INSIGHTS    ((int)(4))
#define EXIT            ((int)(5))

class Account {
    friend ostream &operator<<(ostream &os, const pair<string, double> &trans);
private:
    double expences, income;
    map <string, list<pair<string, double>>> transactions;

public:
    Account() : expences{0}, income{0}, transactions{} {}
    ~Account() = default;

    void input(void);
    void view_trans(void) const;
    void view_summary(void) const;
    void get_insights(void) const;

};

ostream &operator<<(ostream &os, const pair<string, double> &trans)
{
    cout << right
        << setw(10) << setfill(' ') << ""
        << setw(10) << trans.second
        << setw(25) << trans.first; 
    return os;
}

void Account::input(void)
{
    string description{}, category{};
    double amount{};

    cout << "Enter transaction description: ";
    getline(cin, description);
    cout << "Enter transaction amount (positive for income, negative for expense): ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (amount >= 0)
        income += amount;
    else
    {
        if (income + amount >= 0)
            expences += amount;
        else
        {
            cout << "Insufficient Balance!" << endl;
            return;
        }
    }
    
    cout << "Enter category (e.g., Food, Entertainment, Bills): ";
    getline(cin, category);
    category.at(0) = ::toupper(category.at(0));

    transactions[category].push_back(make_pair(description, amount));
}

void Account::view_trans(void) const
{
    cout << left 
        << setw(10) << "\nCategory"
        << right 
        << setw(10) << "Amount"
        << setw(25) << "Description\n"
        << setw(45) << setfill('-') << "" << endl;
    cout << setfill(' ');
    for (const auto &p1 : transactions)
    {
        cout << left << setw(10) << p1.first+":" << endl;
        for (const auto &p2 : p1.second)
        {
            cout << p2 << endl;
        }
    }

    char select{};
    cout << "\nyou want to sort transactions by (y/n): ";
    cin >> select;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (select=='y' || select=='Y')
    {
        cout << "\nTransactions sorted by amount (low to high)." << endl;
        cout << left 
            << setw(10) << "\nCategory"
            << right 
            << setw(10) << "Amount"
            << setw(25) << "Description\n"
            << setw(45) << setfill('-') << "" << endl;
        cout << setfill(' ');
        for (auto p1 : transactions)
        {
            cout << left << setw(10) << p1.first+":" << endl;
            p1.second.sort([] (pair<string, double> &p1, pair<string, double> &p2) {return p1.second < p2.second;});
            for (const auto &p2 : p1.second)
            {
                cout << p2 << endl;
            }
        }
    }
}
void Account::view_summary(void) const
{
    cout << "\nSummary:" << endl;
    cout << "Total income: " << income << endl;
    cout << "Total expences: " << expences << endl;
    cout << "Balance: " << expences+income << endl;
}
void Account::get_insights(void) const
{
    cout << "\nSpending Insights: " << endl;
    if (expences)
    {
        cout << "Total expences: " << abs(expences) << endl;
        for (const auto &p1 : transactions)
        {
            list<pair<string, double>> temp {}; 
            copy_if(p1.second.begin(), p1.second.end(), back_inserter(temp), [] (pair <string, double> p) {return p.second < 0.0;});
            double category_exp = accumulate(temp.begin(), temp.end(), 0.0, [] (double sum, pair <string, double> p2) {return sum + p2.second;});
            double category_per = (category_exp/expences)*100;

            if (category_exp)
                cout << p1.first << " - Spent: " << abs(category_exp) << " (" << category_per << "% of total)" << endl;
        }
    }
    else
        cout << "No expences!" << endl;
}

// for (const auto &p2 : p1.second)
// {            
// }
// category: Bills - Spent: 60 (66.6667% of total)
// category: Food  - Spent: 30 (33.3333% of total)

void print_list(void);

int main(void)
{
    Account a{};
    int select{};

    while (EXIT != select)
    {
        print_list();
        cin >> select;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (select)
        {
        case INPUT_TRANS:
            /* code */
            a.input();
            break;

        case VIEW_TRANS:
            /* code */
            a.view_trans();
            break;

        case VIEW_SUMMARY:
            /* code */
            a.view_summary();
            break;

        case GET_INSIGHTS:
            /* code */
            a.get_insights();
            break;
        
        default:
            break;
        }
    }
    cout << "Exiting the program. Goodbye!" << endl;
    return 0;
}

void print_list(void)
{
    cout << "\n1. Input Transaction\n"
        << "2. View Transactions\n"
        << "3. View Summary\n"
        << "4. Get Insights\n"
        << "5. Exit\n"
        << "Choose an option: ";
}