#include <bits/stdc++.h>

using namespace std;

#define rl09 romill_09
#define int long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define vinput(a)     \
    for (auto &i : a) \
        cin >> i;
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define printP(a)    \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define printR(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

const int MOD = 1e9 + 7;

struct Robot
{
    int px, py;
    int vx, vy;
};

vector<Robot> input()
{
    vector<Robot> robots;
    string line;
    while (getline(cin, line))
    {
        Robot robot;
        stringstream ss(line);

        string temp;
        ss >> temp;
        size_t comma = temp.find(',');
        robot.px = stoi(temp.substr(2, comma - 2));
        robot.py = stoi(temp.substr(comma + 1));

        ss >> temp >> temp;
        comma = temp.find(',');
        robot.vx = stoi(temp.substr(2, comma - 2));
        robot.vy = stoi(temp.substr(comma + 1));

        robots.push_back(robot);
    }
    return robots;
}

void movement(vector<Robot> &robots, int seconds, int width, int height)
{
    for (auto &robot : robots) 
    {
        robot.px = (robot.px + (robot.vx * seconds)) % width;
        robot.py = (robot.py + (robot.vy * seconds)) % height;

        if (robot.px < 0)
        {
            robot.px += width;
        }

        if (robot.py < 0)
        {
            robot.py += height;
        }
    }
}

void updateGrid(const vector<Robot> &robots, vector<vi> &grid)
{
    for (const auto &robot : robots)
    {
        grid[robot.py][robot.px]++;
    }
}

int safetyFactor(const vector<vi> &grid, int width, int height)
{
    int quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
    int midRow = grid.size() / 2;
    int midCol = grid[0].size() / 2;

    // Top-left
    for (int i = 0; i < midRow; i++)
    {
        for (int j = 0; j < midCol; j++)
        {
            quadrant1 += grid[i][j];
        }
    }

    // Top-right
    for (int i = 0; i < midRow; i++)
    {
        for (int j = midCol + 1; j < grid[0].size(); j++)
        {
            quadrant2 += grid[i][j];
        }
    }

    // Bottom-left
    for (int i = midRow + 1; i < grid.size(); i++)
    {
        for (int j = 0; j < midCol; j++)
        {
            quadrant3 += grid[i][j];
        }
    }

    // Bottom-right
    for (int i = midRow + 1; i < grid.size(); i++)
    {
        for (int j = midCol + 1; j < grid[0].size(); j++)
        {
            quadrant4 += grid[i][j];
        }
    }

    return quadrant1 * quadrant2 * quadrant3 * quadrant4;
}
void solve()
{
    const int width = 101, height = 103, seconds = 100;

    vector<Robot> robots = input();

    movement(robots, seconds, width, height);

    vector<vi> grid(height, vi(width, 0));

    updateGrid(robots, grid);

    int safety_factor = safetyFactor(grid, width, height);

    cout << safety_factor << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}