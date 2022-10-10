//Dependencies: 
//yarn add express cors twilio 

const express = require('express'); 
const cors = require('cors');
const twilio = require('twilio'); 

//twilio requirements -- Texting API 
const accountSid = 'AC2f71dc2232dd6cd936b9c8f420bd848f';
const authToken = '4a4d5fdd099721e5de9387fe4e3d964b'; 
const client = new twilio(accountSid, authToken);

const app = express(); //alias

app.use(cors()); //Blocks browser from restricting any data

//Welcome Page for the Server 
app.get('/', (req, res) => {
    res.send('Welcome to the Express Server')
})

//Twilio 
app.get('/send-text', (req, res) => {
    //Welcome Message
    res.send('Hello to the Twilio Server')

    //_GET Variables
    const { recipient, textmessage } = req.query;


    //Send Text
    client.messages.create({
        body: textmessage,
        to: "+91" + recipient,  // Text this number
        from: '+19124522256' // From a valid Twilio number
    }).then((message) => console.log(message.body));
})

app.listen(4000, () => console.log("Running on Port 4000"))