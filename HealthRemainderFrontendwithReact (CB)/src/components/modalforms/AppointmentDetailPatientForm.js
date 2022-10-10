import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import React, { Component } from 'react'
import { Link, withRouter } from 'react-router-dom';

class ModalForm extends Component {
  constructor(props) {
    super(props)

    this.state = {
        id: null
    }
    this.changeIdHandler = this.changeIdHandler.bind(this);
  }

  changeIdHandler= (event) => {
    this.setState({id: event.target.value});
  }
  
  
  render(){
    return(
        <div>
      <Modal 
        show={this.props.isOpen} 
        onHide={this.props.closeModal}
      >
      <Modal.Header closeButton>
        <Modal.Title>Get Appointment Details</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <Form.Label>Patient Id </Form.Label>
              <Form.Control type="number" onChange={this.changeIdHandler} value={this.state.id} placeholder="Enter Patient Id"/>           
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          
        <Link to={"/viewAppointmentDetails/pat/"+this.state.id} className="btn btn-primary">Submit</Link>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(ModalForm);