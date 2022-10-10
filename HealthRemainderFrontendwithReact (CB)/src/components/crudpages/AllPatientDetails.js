import React, { Component } from 'react';
import AllPatientDetailsServices from '../../services/AllPatientDetailsServices';
import NavigationAdmin from '../navBars/NavigationAdmin';
import ReactTable from "react-table-6";
import "../../cssComponents/react-table.css";

class AllDoctorDetails extends Component {
    constructor(props){
        super(props)
        this.state={
            patient:[]
        }     
   
    }
      
    componentDidMount(){
        AllPatientDetailsServices.getPatients().then((response) => {
            console.log(response);
            this.setState({patient : response.data})
        });
    }

    render() {
        const columns = [{
            Header: 'ID',
            accessor: 'patientId'
          },{
            Header: 'Email',
            accessor: 'patientEmail'
          },{
            Header: 'Name',
            accessor: 'patientName'
          },{
            Header: 'Mobile Number',
            accessor: 'patientMobile'
          },{
            Header: 'Age',
            accessor: 'patientAge'
          },{
            Header: 'Height',
            accessor: 'patientHeight'
          },{
            Header: 'Weight',
            accessor: 'patientWeight'
          }]
        return (
            <div>
                <NavigationAdmin />
              <ReactTable
                data={this.state.patient}
                columns={columns}
                defaultPageSize = {5}
                pageSizeOptions = {[5, 10]}
              />
          </div>  
        );
    }
}

export default AllDoctorDetails;