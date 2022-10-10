import React, { Component } from "react";
import { Card } from "react-bootstrap";
import AppointmentDetailForm from "./modalforms/AppointmentDetailDoctorForm";
import AppointmentSlotAddModal from "./modalforms/AppointmentSlotAddModal";
import DoctorProfileModal from "./modalforms/DoctorProfileModal";
import img3 from "../images/view_app.jpg";
import img2 from "../images/disease.jpg";
import img1 from "../images/Slot.png";
import img4 from "../images/profile.png";

export class DoctorBody extends Component {
  state = {
    isAppointmentDetailsOpen: false,
    isSlotAddOpen: false,
    isDocProfileOpen: false,
  };

  appointmentDetailOpenModal = () =>
    this.setState({ isAppointmentDetailsOpen: true });
  appointmentDetailCloseModal = () =>
    this.setState({ isAppointmentDetailsOpen: false });
  docProfileOpenModal = () => this.setState({ isDocProfileOpen: true });

  slotAddOpenModal = () => this.setState({ isSlotAddOpen: true });
  slotAddCloseModal = () => this.setState({ isSlotAddOpen: false });
  docProfileCloseModal = () => this.setState({ isDocProfileOpen: false });

  render() {
    return (
      <div className="container">
        <p> </p>
        <h2> Welcome Doctor! </h2>
        <p> </p>
        <div className="row m-4">
          <div className="col-sm">
            <Card style={{ width: "80%" }}>
              <Card.Img variant="top" src={img1} style={{ height: "20rem" }} />
              <Card.Body>
                <Card.Title>
                  <h5>Fill Up Slots</h5>
                </Card.Title>
                <Card.Text>
                  <p>Click here to Fill up the Appointment Slots</p>
                </Card.Text>
              </Card.Body>
              <Card.Footer>
                <Card.Link
                  className="btn btn-primary"
                  onClick={this.slotAddOpenModal}
                >
                  Fill Slots
                </Card.Link>
                {this.state.isSlotAddOpen ? (
                  <AppointmentSlotAddModal
                    closeModal={this.slotAddCloseModal}
                    isOpen={this.state.isSlotAddOpen}
                    updateTips={this.updateTips}
                  />
                ) : null}
              </Card.Footer>
            </Card>
          </div>

          <div className="col-sm">
            <Card style={{ width: "80%" }}>
              <Card.Img variant="top" src={img2} style={{ height: "20rem" }} />
              <Card.Body>
                <Card.Title>
                  <h5>Disease Info</h5>
                </Card.Title>
                <Card.Text>
                  <p>Click here to get a detailed list of diseases.</p>
                </Card.Text>
              </Card.Body>
              <Card.Footer>
                <Card.Link href="/searchpage" className="btn btn-primary">
                  Disease Info
                </Card.Link>
              </Card.Footer>
            </Card>
          </div>
        </div>
        <div className="row m-4">
          <div className="col-sm">
            <Card style={{ width: "80%" }}>
              <Card.Img variant="top" src={img3} style={{ height: "20rem" }} />
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
                  onClick={this.appointmentDetailOpenModal}
                >
                  Get Details
                </Card.Link>
                {this.state.isAppointmentDetailsOpen ? (
                  <AppointmentDetailForm
                    closeModal={this.appointmentDetailCloseModal}
                    isOpen={this.state.isAppointmentDetailsOpen}
                    updateTips={this.updateTips}
                  />
                ) : null}
              </Card.Footer>
            </Card>
          </div>
          <div className="col-sm">
            <Card style={{ width: "80%" }}>
              <Card.Img variant="top" src={img4} style={{ height: "20rem" }} />
              <Card.Body>
                <Card.Title>
                  <h5>Profile</h5>
                </Card.Title>
                <Card.Text>
                  <p>Click here to check your profile</p>
                </Card.Text>
              </Card.Body>
              <Card.Footer>
                <Card.Link
                  className="btn btn-primary"
                  onClick={this.docProfileOpenModal}
                >
                  Get Details
                </Card.Link>
                {this.state.isDocProfileOpen ? (
                  <DoctorProfileModal
                    closeModal={this.docProfileCloseModal}
                    isOpen={this.state.isDocProfileOpen}
                  />
                ) : null}
              </Card.Footer>
            </Card>
          </div>
        </div>
      </div>
    );
  }
}

export default DoctorBody;
