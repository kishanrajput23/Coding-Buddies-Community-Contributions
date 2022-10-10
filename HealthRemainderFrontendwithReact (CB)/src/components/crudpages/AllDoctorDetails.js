import React, { Component } from 'react';
import AllDoctorDetailsServices from '../../services/AllDoctorDetailsServices';
import NavigationAdmin from '../navBars/NavigationAdmin';
import ReactTable from "react-table-6";
import "../../cssComponents/react-table.css";

class AllDoctorDetails extends Component {
    constructor(props){
        super(props)
        this.state={
            doctor:[]
        }     
   
    }
      
    componentDidMount(){
        AllDoctorDetailsServices.getAllDoctors().then((response) => {
            console.log(response);
            this.setState({doctor : response.data})
        });
    }

    render() {
        
        const columns = [{
            Header: 'ID',
            accessor: 'doctorId'
          },{
            Header: 'Verification Status',
            accessor: 'verfStatus'
          },{
            Header: 'Name',
            accessor: 'doctorName'
          },{
            Header: 'Specialization',
            accessor: 'doctorSpec'
          },{
            Header: 'Certificate Info',
            accessor: 'doctorCertFile'
          }]

        return (
            <div>
                <NavigationAdmin />
              <ReactTable
                data={this.state.doctor}
                columns={columns}
                defaultPageSize = {5}
                pageSizeOptions = {[5, 10]}
              />
          </div>    
        );
    }
}

export default AllDoctorDetails;