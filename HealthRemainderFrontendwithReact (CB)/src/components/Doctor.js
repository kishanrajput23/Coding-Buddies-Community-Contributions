import React, { Component } from "react";
import DoctorNavigation from "./navBars/DoctorNavigation";
import DoctorBody from "./DoctorBody";

export class Doctor extends Component {
  render() {
    return (
      <div>
        <DoctorNavigation />
        <DoctorBody />
      </div>
    );
  }
}

export default Doctor;
