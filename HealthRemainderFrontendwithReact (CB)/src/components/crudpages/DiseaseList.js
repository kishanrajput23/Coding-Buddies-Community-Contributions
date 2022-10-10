import React, { Component } from 'react';
import DiseaseListServices from '../../services/DiseaseListServices';
import DiseaseUpdateModal from '../modalforms/DiseaseUpdateModal';
import NavigationAdmin from '../navBars/NavigationAdmin';
import DiseaseAddModal from '../modalforms/DiseaseAddModal';
import DiseaseDeleteModal from '../modalforms/DiseaseDeleteModal';

class DiseaseList extends Component {
    constructor(props){
        super(props)
        this.state={
            diseases:[]
        }     
        this.changeIdHandler=this.changeIdHandler.bind(this);    
   
    }
    state = {
        isOpen: false,
        isAddOpen: false,
        isDeleteOpen: false,
        id: null,
      }      
    
      openModal = () => this.setState({ isOpen: true });
      closeModal = () => {this.setState({ isOpen: false })}      

      openAddModal = () => this.setState({ isAddOpen: true });
      closeAddModal = () => {this.setState({ isAddOpen: false }); } 
      
      openDeleteModal = () => this.setState({ isDeleteOpen: true });
      closeDeleteModal = () => {this.setState({ isDeleteOpen: false }); } 

      changeIdHandler= (e) => {
        this.setState({id: e});
        console.log(this.state.id);
      }
      
    componentDidMount(){
        DiseaseListServices.viewDisease().then((response) => {
            console.log(response);
            this.setState({diseases : response.data})
        });
    }
    render() {
        return (
            <div>
                <div>
                     <NavigationAdmin />
                </div>
                <p> </p>
                <div className="container">
                    <h3> Diseases</h3>
                    <div className="row">
                        <button className="btn btn-info" onClick= {this.openAddModal}>Add New Disease</button>
                    </div>
                    <p> </p>
                    <table className="table table-hover table-bordered">
                        <thead>
                            <tr>
                                <th> ID</th>
                                <th> Name</th>
                                <th> Information</th>
                                <th> Keys</th>
                                <th> Actions</th>
                            </tr>
                        </thead>

                        <tbody>
                           {
                               this.state.diseases.map(
                                disease =>
                                   <tr key = {disease.diseaseId}>
                                       <td> {disease.diseaseId}</td> 
                                       <td> {disease.diseaseName}</td>
                                       <td> {disease.diseaseInfo}</td>
                                       <td> {disease.diseaseKeys}</td>
                                       <td>
                                        <button className="btn btn-outline-info" 
                                                onClick={()=>{this.changeIdHandler(disease.diseaseId);this.openModal();}}>
                                                    Update</button>
                                       {'  '} <button className="btn btn-outline-info" 
                                                onClick={()=>{this.changeIdHandler(disease.diseaseId);this.openDeleteModal();}}>
                                                    Delete</button>
                                        </td>
                                   </tr>
                               )
                           }
                        </tbody>
                    </table>
                </div>
                { this.state.isAddOpen ?   
                                                <DiseaseAddModal 
                                                closeAddModal={this.closeAddModal} 
                                                isAddOpen={this.state.isAddOpen} 
                                                addDisease={this.addDisease} 
                                                /> : null 
                                            }
                { this.state.isOpen ?   
                                                <DiseaseUpdateModal 
                                                closeModal={this.closeModal} 
                                                isOpen={this.state.isOpen} 
                                                updateDisease={this.updateDisease} id={this.state.id} 
                                                /> : null 
                                            }
                { this.state.isDeleteOpen ?   
                                                <DiseaseDeleteModal 
                                                closeDeleteModal={this.closeDeleteModal} 
                                                isDeleteOpen={this.state.isDeleteOpen} 
                                                deleteDisease={this.deleteDisease} id={this.state.id} 
                                                /> : null 
                                            }
            </div>
        );
    }
}

export default DiseaseList;