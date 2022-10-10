import React from 'react';
import { Link, withRouter } from 'react-router-dom';

const DiseaseAllList = ({diseaseList=[]}) => {
    // constructor(props){
    //     super(props)

    //     this.callViewingPage = this.callViewingPage.bind(this);
    // }

    // callViewingPage=() => {

    // }

  return (
    <>
    { diseaseList.map((data,index) => {
        if (data) {
          return (
            
            <div key={data.diseaseName}>
                <div> <p> </p></div>
                <div className="container">
                <table className="table table-hover ">
                    <tbody>
                        <tr>
                            <td>{data.diseaseName}  </td>
                            <td><Link to={"/viewInfo/"+data.diseaseId+"/"+data.diseaseName+"/"+data.diseaseInfo+"/"+data.diseaseKeys} 
                            className="btn btn-primary">See More</Link>
                                                   </td>
                        </tr>
                    </tbody>
              </table>
              </div>
	        </div>	
    	   )	
    	}
    	return null
    }) }
    </>
  );
}

export default withRouter(DiseaseAllList);