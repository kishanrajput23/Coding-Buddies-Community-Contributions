import React, { Component } from 'react';
import AppointmentSlotServices from '../../services/AppointmentSlotServices';
import BookAppointmentModalForm from '../modalforms/BookAppointmentModalForm';
import NavigationPatient from '../navBars/NavigationPatient';
import moment from 'moment';



class ViewAllSlots extends Component {
    constructor(props){
        super(props)
        this.state={
            slots:[]
        }     
        this.sendDoctorIdHandler=this.sendDoctorIdHandler.bind(this);
    }
      state = {
        isOpen: false,
        id:null
      }      
    
      openModal = (index) => {this.setState({ isOpen: true})};
      closeModal = () => {this.setState({ isOpen: false })}   

      
    sendDoctorIdHandler= (e) => {
        this.setState({id: e});
        console.log(this.state.id);
    }

    
      
    componentDidMount(){
        AppointmentSlotServices.viewSlots().then((response) => {
            console.log(response);
            this.setState({slots : response.data})
        });
    }
    render() {
        return (
            <div>
                <div>
                    <NavigationPatient/>
                </div>
                <p> </p>
                <div className="container">
                    <h3> Slots available:</h3>
                    <p> </p>
                    <table className="table table-hover table-bordered">
                        <thead>
                            <tr>
                                <th> Doctor ID</th>
                                <th> Doctor Name</th>
                                <th> Date</th>
                                <th> Start Time</th>
                                <th> End Time</th>
                                <th> Booking open</th>
                            </tr>
                        </thead>

                        <tbody>
                           {
                               this.state.slots.map(
                                slot =>
                                   <tr key = {slot.pk.doctorId}>
                                       <td> {slot.pk.doctorId}</td> 
                                       <td> {slot.doctorName}</td>
                                       <td> {moment(slot.pk.doctorDate).format("DD-MM-YYYY")}</td>
                                       <td> {slot.doctorStartTime}</td>
                                       <td> {slot.doctorEndTime}</td>
                                       <td>
                                        <button className="btn btn-outline-info" 
                                                onClick={()=>{this.sendDoctorIdHandler(slot); this.openModal();}}>
                                                    Book Appointment</button>
                                       </td>
                                   </tr>
                               )
                           }
                        </tbody>
                    </table>
                </div>
                {this.state.isOpen ?   
                                                <BookAppointmentModalForm
                                                closeModal={this.closeModal} 
                                                isOpen={this.state.isOpen} 
                                                updateDisease={this.updateDisease} id={this.state.id} 
                                                /> : null 
                                            }
            </div>
        );
    }
}

export default ViewAllSlots;