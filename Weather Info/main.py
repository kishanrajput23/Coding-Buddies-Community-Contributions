import json;
import requests;
import config;

city  =  input("Enter your city name : ");
url = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + config.api_key;

data = requests.get(url);


if data.status_code == 200:

    data = data.json();
    # converting the JSON data to JSON string
    data  = json.dumps(data);

    # converting JSON string to python object
    parsedData = json.loads(data)

    main = parsedData['main'];

    print("\nWeather Info of " + city.capitalize())
    print("Temperature : "  + str(main['temp']));
    print("Feels Like Temperature : " + str(main['feels_like']));
    print("Maximum Temperature : " + str(main['temp_max']));
    print("Minimum Temperature : " + str(main['temp_min']));

else:
    print("Invalid City Name")
