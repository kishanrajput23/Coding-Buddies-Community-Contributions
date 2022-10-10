import React, { Component } from "react";
import AppointmentDetailsServices from "../../services/AppointmentDetailsServices";
import NavigationDiseaseSearch from "../navBars/NavigationDiseaseSearch";
import { Card } from "react-bootstrap";
import img1 from "../../images/appoint.jpg";
import "../../cssComponents/appointmentDetails.css";
import moment from 'moment';

class AppointmentDetailsComponent extends Component {
  constructor(props) {
    super(props);

    this.state = {
      id: this.props.match.params.id,
      type: this.props.match.params.type,
      appointments: {},
    };
  }

  componentDidMount() {
    console.log(this.state.id);
    console.log(this.state.type);
    if (this.state.type === "doc") {
      AppointmentDetailsServices.getAppointmentDetailsByDoctorId(
        this.state.id
      ).then((res) => {
        if (res.data.errorCode) {
          alert("Invalid Doctor Id or Appointment Not found");
          window.location = "/doctor";
        } else {
          this.setState({ appointments: res.data });
        }
      });
    } else {
      AppointmentDetailsServices.getAppointmentDetailsByPatientId(
        this.state.id
      ).then((res) => {
        if (res.data.errorCode) {
          alert("Invalid Patient Id or Appointment Not found");
          window.location = "/patient";
        } else {
          this.setState({ appointments: res.data });
        }
      });
    }
  }

  render() {
    return (
      <div>
        <NavigationDiseaseSearch />
        <div class="center">
          <br></br>

          <Card style={{ height: "37rem" }}>
            <Card.Img variant="top" src={img1} style={{ height: "17rem" }} />
            <Card.Title>Your Appointment Details are:</Card.Title>
            <Card.Body>
              <Card.Text>
                <label>Doctor Id: {this.state.appointments.doctorId}</label>
                <br></br>
                <label>Doctor Name: {this.state.appointments.doctorName}</label>
                <br></br>
                <label>Patient Id: {this.state.appointments.patientId}</label>
                <br></br>
                <label>
                  Patient Name: {this.state.appointments.patientName}
                </label>
                <br></br>
                <label>
                  Appointment Date: {moment(this.state.appointments.doctorDate).format("DD-MM-YYYY")}
                </label>
                <br></br>
                <label>
                  Start Time: {this.state.appointments.doctorStartTime}
                </label>
                <br></br>
                <label>End Time: {this.state.appointments.doctorEndTime}</label>
              </Card.Text>
            </Card.Body>
            <Card.Footer></Card.Footer>
          </Card>
        </div>
      </div>
    );
  }
}

export default AppointmentDetailsComponent;
