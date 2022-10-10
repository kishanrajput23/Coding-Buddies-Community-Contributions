import React, {Component} from 'react';
import {Form, Modal} from 'react-bootstrap'
import {Link} from 'react-router-dom'
import AllDoctorDetailsServices from '../../services/AllDoctorDetailsServices'

class DoctorProfileModal extends Component{
    constructor(props){
        super(props);
        this.state={
            docId:null
        }
        this.docIdchanged=this.docIdchanged.bind(this)
        this.handleSubmit=this.handleSubmit.bind(this)
    }
    docIdchanged(id){
        this.setState({docId:id.target.value})
        console.log(id.target.value)
    }
    handleSubmit = () =>{
        AllDoctorDetailsServices.getDoctorById(this.state.docId)
        .then(res=>{
            if(res.data.errorCode){
                alert('Doctor not found. Lets create a new one')
                window.location='createDoc'
            }
            else{
                alert('Doctor found. Lets update profile')
                window.location='updateDoc/'+this.state.docId
            }
        })
    }
    render(){
        return(<>
        <Modal 
        show={this.props.isOpen} 
        onHide={this.props.closeModal}
      >
      <Modal.Header closeButton>
        <Modal.Title>Enter Doctor ID</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <Form.Label>Doctor Id </Form.Label>
              <Form.Control type="number" onChange={this.docIdchanged} value={this.state.id} placeholder="Enter Doctor Id"/>           
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          
        <Link onClick={this.handleSubmit} className="btn btn-primary">Submit</Link>
      </Modal.Footer>
    </Modal>
        </>);
    }
}

export default DoctorProfileModal;