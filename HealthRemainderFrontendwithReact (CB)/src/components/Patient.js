import React, { Component } from "react";
import { Card } from "react-bootstrap";
import NavigationPatient from "./navBars/NavigationPatient";
import AppointmentDetailPatientForm from "./modalforms/AppointmentDetailPatientForm";
import MentalRatingModal from "./modalforms/MentalRatingModal";
import DietInfoFindModal from "./modalforms/DietInfoFindModal";
import PatientProfileModal from "./modalforms/PatientProfileModal";
import img1 from "../images/Slot.png";
import img2 from "../images/view_app.jpg";
import img3 from "../images/mental.jpg";
import img4 from "../images/reminder.png";
import img5 from "../images/disease.jpg";
import img6 from "../images/diet.jpg";
import img7 from "../images/profile.png";

export class Patient extends Component {
  state = {
    isAppDetOpen: false,
    isMentalRatingOpen: false,
    isDietInfoFindOpen: false,
    isPatientProfileOpen: false,
  };
  AppDetOpen = () => this.setState({ isAppDetOpen: true });
  AppDetClose = () => this.setState({ isAppDetOpen: false });

  mentalRatingOpen = () => {
    this.setState({ isMentalRatingOpen: true });
    console.log(this.state.isMentalRatingOpen);
  };
  mentalRatingClose = () => this.setState({ isMentalRatingOpen: false });

  dietInfoFindOpen = () => this.setState({ isDietInfoFindOpen: true });
  dietInfoFindClose = () => this.setState({ isDietInfoFindOpen: false });

  patientProfileOpen = () => this.setState({ isPatientProfileOpen: true });
  patientProfileClose = () => this.setState({ isPatientProfileOpen: false });

  render() {
    return (
      <div>
        <NavigationPatient />
        <div className="container">
          <p> </p>
          <h2> Welcome Patient! </h2>
          <p> </p>
          <div className="row">
            <div className="col-sm">
              <Card>
                <Card.Img
                  variant="top"
                  src={img1}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Check Slot and Book Appointment</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to see all the available Appointment Slots and
                      Book your Appointment Now!
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/viewAllSlots" className="btn btn-primary">
                    Slots/Book Appointment
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card style={{ height: "35.8rem" }}>
                <Card.Img
                  variant="top"
                  src={img2}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Appointment Details</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>Click here to get all the Appointment Details</p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link
                    className="btn btn-primary"
                    onClick={this.AppDetOpen}
                  >
                    Get Details
                  </Card.Link>
                  {this.state.isAppDetOpen ? (
                    <AppointmentDetailPatientForm
                      closeModal={this.AppDetClose}
                      isOpen={this.state.isAppDetOpen}
                      updateTips={this.updateTips}
                    />
                  ) : null}
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card style={{ height: "35.8rem" }}>
                <Card.Img
                  variant="top"
                  src={img3}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Mental Health Rating</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>Enter your mental health rating for today</p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link
                    className="btn btn-primary"
                    onClick={this.mentalRatingOpen}
                  >
                    Enter rating
                  </Card.Link>
                  {this.state.isMentalRatingOpen ? (
                    <MentalRatingModal
                      handleClose={this.mentalRatingClose}
                      show={this.state.isMentalRatingOpen}
                    />
                  ) : null}
                </Card.Footer>
              </Card>
            </div>
          </div>{" "}
          <br></br>
          <br></br>
          <div className="row">
            <div className="col-sm">
              <Card>
                <Card.Img
                  variant="top"
                  src={img4}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Set Reminders</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to set reminders for your medications
                      time-to-time
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/setreminder" className="btn btn-primary">
                    Set Reminder
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card>
                <Card.Img
                  variant="top"
                  src={img5}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Disease Info</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to get a list of diseases along with their
                      descriptions.
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link href="/searchpage" className="btn btn-primary">
                    Disease Info
                  </Card.Link>
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card>
                <Card.Img
                  variant="top"
                  src={img6}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Diet Info</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>
                      Click here to find a perfect diet chart according to your
                      BMI
                    </p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link
                    className="btn btn-primary"
                    onClick={this.dietInfoFindOpen}
                  >
                    Diet chart
                  </Card.Link>
                  {this.state.isDietInfoFindOpen ? (
                    <DietInfoFindModal
                      closeModal={this.dietInfoFindClose}
                      isOpen={this.state.isDietInfoFindOpen}
                      findDiet={this.findDiet}
                    />
                  ) : null}
                </Card.Footer>
              </Card>
            </div>
            <div className="col-sm">
              <Card style={{ height: "34.3rem" }}>
                <Card.Img
                  variant="top"
                  src={img7}
                  style={{ height: "20rem" }}
                />
                <Card.Body>
                  <Card.Title>
                    <h5>Profile</h5>
                  </Card.Title>
                  <Card.Text>
                    <p>Click here to set or update your profile</p>
                  </Card.Text>
                </Card.Body>
                <Card.Footer>
                  <Card.Link
                    className="btn btn-primary"
                    onClick={this.patientProfileOpen}
                  >
                    Set/Update Profile
                  </Card.Link>
                  {this.state.isPatientProfileOpen ? (
                    <PatientProfileModal
                      closeModal={this.patientProfileClose}
                      isOpen={this.state.isPatientProfileOpen}
                      findID={this.findID}
                    />
                  ) : null}
                </Card.Footer>
              </Card>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

export default Patient;
