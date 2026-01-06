enum class ServerStatus {
    Inactive = 1,
    Running = 2,
    Restarting = 3,
    Terminated = 4
};

enum class FeatureName {
    WeatherForecast = 0,
    WebSearch = 1,
    StockPrices = 2
};

enum class FeatureStatus {
    Available = 0,
    CurrentlyBroken = 1,
    Finished = 2,
    InProgress = 3,
    TemporarilyUnavailable = 4
};
