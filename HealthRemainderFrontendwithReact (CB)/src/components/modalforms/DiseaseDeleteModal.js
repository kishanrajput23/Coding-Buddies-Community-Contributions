import Form from 'react-bootstrap/Form'
import Modal from 'react-bootstrap/Modal'
import Button from 'react-bootstrap/button'
import React, { Component } from 'react'
import { withRouter } from 'react-router-dom';
import DiseaseListServices from '../../services/DiseaseListServices'


class DiseaseDeleteModal extends Component {
  constructor(props) {
    super(props)

    // this.state = {
    //     id:null,
    // }
    //this.changeIdHandler = this.changeIdHandler.bind(this);
    this.deleteDisease = this.deleteDisease.bind(this);
}

  // changeIdHandler= (event) => {
  //   this.setState({id: event.target.value});
  //   console.log(this.state.id);
  // }

  deleteDisease = () => {
    //e.preventDefault();
    console.log('id => ' + JSON.stringify(this.props.id));
    DiseaseListServices.deleteDisease(this.props.id).then( res => {
        console.log(res);
        window.location.reload();
    });
  }

  render(){
    return(
        <div>
      <Modal 
        show={this.props.isDeleteOpen} 
        onHide={this.props.closeDeleteModal}
      >
      <Modal.Header closeButton>
        <Modal.Title>Delete Disease</Modal.Title>
      </Modal.Header>
      <Modal.Body>
          <Form.Group >
              <div> Are you sure you want to delete Disease ID {this.props.id}?</div>       
          </Form.Group>
      </Modal.Body>
      <Modal.Footer>
          <Button variant="primary" type="submit" onClick={() => {this.deleteDisease();}}>
              Yes
          </Button>
          <Button variant="primary"  onClick={() => {this.props.closeDeleteModal()}}>
                  No
          </Button>
      </Modal.Footer>
    </Modal>
    </div>
    )
  }
}

export default withRouter(DiseaseDeleteModal);