import nltk
from nltk.chat.util import Chat, reflections
from nltk.sentiment.vader import SentimentIntensityAnalyzer

# Download the VADER lexicon if you haven't already
nltk.download('vader_lexicon')

# Create a sentiment analyzer instance
analyzer = SentimentIntensityAnalyzer()

# Define a list of patterns and responses for the chatbot.
psychologist_responses = [
    (r'hello|hi|hey', ['Hello!', 'Hi there!', 'How can I help you today?']),
    (r'how are you', ['I am just a computer program, but I am here to help you. How are you feeling today?']),
    (r'i feel (.*)', ['I am here to listen. Can you tell me more about why you feel {}?', 'I see. Why do you feel {}?', 'Im here to listen.']),
    (r'(.*) help (.*)', ['I am here to help. Can you tell me more about your concerns?', 'I am here to listen and provide support.']),
    (r'(.*) (depressed|anxious|stressed|lonely|worried)', ['I\'m sorry to hear that. It\'s important to talk about your feelings. Can you share more about what you are going through?', 'I\'m here to listen and provide support.']),
    (r'quit', ['Thank you for talking with me. Please consider seeking professional help if you\'re experiencing mental health issues.']),
]

# Create a chatbot instance with the defined patterns and responses.
psychologist_chatbot = Chat(psychologist_responses, reflections)

# Start the conversation.
print("Mental Health Chatbot: Hello, how can I assist you today? Type 'quit' to exit.")
while True:
    user_input = input("You: ")
    if user_input.lower() == 'quit':
        print("Mental Health Chatbot: Thank you for talking with me. Please consider seeking professional help if needed.")
        break
    
    # Perform sentiment analysis on the user's input
    sentiment_scores = analyzer.polarity_scores(user_input)
    sentiment = sentiment_scores['compound']
    
    response = psychologist_chatbot.respond(user_input)
    print("Sentiment Analysis Result: ", sentiment)
    print("Mental Health Chatbot:", response)
