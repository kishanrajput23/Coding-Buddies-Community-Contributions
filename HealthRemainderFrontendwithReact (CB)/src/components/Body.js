import React, { Component } from "react";
import { Card } from "react-bootstrap";
import img1 from "../images/doc_img.jpg";
import img2 from "../images/admin12.jpg";
import img3 from "../images/patient12.jpg";
import img4 from "../images/body.jpg";
import Navigation from "./navBars/Navigation";
import '../cssComponents/features.css'

export class Body extends Component {
  render() {
    return (
      <div>
        <Navigation />
        <div className="container">
          <p> </p>
          <h2> Welcome User! </h2>
          <p> </p>
          <div>
            <p> </p>
            <br></br>
          </div>
          <h2>Features of our Web-App</h2><br></br>
          <div className="row">
          <div className="col-sm-3 features">
                <img src={img4} alt="img"/>
          </div>
          <div className="col-sm features">
            <div>
              <p> </p>
            </div>
           
            <p>
              Create personalised medicine/diet alarms, and be notified via SMS/
              Whatsapp.<br></br>Find a suitable diet for you according to your
              BMI in our app.<br></br> Keep track of your diet patterns
              regularly simply by logging in.<br></br> Win weekly streaks 
              following your diet, with the help of our tracker!<br></br>Tell us
              how you feel mentally, and we'll help you fell better with our
              Health Tips.<br></br>Consult(Book appoinments with) a specialised
              Doctor via our application anywhere, anytime.<br></br> Save your
              medical history to your profile for easy consultations with
              Doctors. <br></br> Search for a Disease and find precise
              information on our app.
            </p>
          </div>
          </div>
          <br></br>
          <div className="row">
            <p> </p>
            <div className="col-sm">
              <h2>Identify yourself here</h2>
            </div>
          </div>
          <div>
            <p> </p>
          </div>
          <div className="row">
            <p> </p>
            <div className="col-sm">
              <Card style={{ height: "37rem" }}>
                <Card.Img
                  variant="top"
                  src={img1}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Doctor</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to Login as a Doctor and get access to various
                      features of filling up slots, looking up to your
                      appointments, get details of various diseases,etc.
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/Doctor" className="btn btn-primary">
                    Login as Doctor
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card style={{ height: "37rem" }}>
                <Card.Img
                  variant="top"
                  src={img2}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Admin</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to Login as Admin of the Web-Application. This
                      is only reserved for the Admin of the Web-Application
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/Admin" className="btn btn-primary">
                    Login as Admin
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card style={{height:"36.9rem"}}>
                <Card.Img
                  variant="top"
                  src={img3}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Patient</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to Login as a Patient and get access to various
                      features of booking appointments, setting alarms for
                      medications, track your mental health and diet, etc.
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/patient" className="btn btn-primary">
                    Login as Patient
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

export default Body;
