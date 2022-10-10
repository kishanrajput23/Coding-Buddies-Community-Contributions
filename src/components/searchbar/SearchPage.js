import React, { useState, useEffect } from 'react';
import SearchBar from './SearchBar';
import DiseaseAllList from './DiseaseAllList';
import DiseaseListServices from '../../services/DiseaseListServices';
import NavigationDiseaseSearch from '../navBars/NavigationDiseaseSearch';

const SearchPage = (props) => {
  const [input, setInput] = useState('');
  const [diseaseListDefault, setdiseaseListDefault] = useState();
  const [diseaseList, setdiseaseList] = useState();

  const fetchData = async () => {
    return await 
      DiseaseListServices.viewDisease().then((response)=> {
         setdiseaseList(response.data) 
         setdiseaseListDefault(response.data)
       });}

  const updateInput = async (input) => {
     const filtered = diseaseListDefault.filter(disease => {
      return disease.diseaseName.toLowerCase().includes(input.toLowerCase())
     })
     setInput(input);
     setdiseaseList(filtered);
  }

  useEffect( () => {fetchData()},[]);
	
  return (
    <>
      <NavigationDiseaseSearch />
      <div><p> </p></div> 
      <h2>List of Diseases</h2>
      <div><p> </p></div>      
      <SearchBar 
       input={input} 
       setKeyword={updateInput}
      />
      <div> <p> </p></div>
      <div className="container">
      <table className="table table-hover table-bordered " bgcolor="#D5F5E3">
                    <thead>
                        <tr>
                            <th> Disease </th>
                            <th> Actions </th>
                        </tr>
                    </thead>
                    </table>
                    </div>
      <DiseaseAllList diseaseList={diseaseList}/>
    </>
   );
}

export default SearchPage