import App from './App';
import Patient from './components/Patient'
import React from 'react';
import {create} from 'react-test-renderer'
import Admin from './components/Admin';
import Doctor from './components/Doctor';
import Footer from './components/Footer';


describe('App Snapshot Test',()=>{
  test('Checking Snapshot', () => {
    let tree=create(<App/>)
    expect(tree.toJSON()).toMatchSnapshot();
})
})


describe('Admin Snapshot Test',()=>{
  test('Checking Snapshot', () => {
    let tree=create(<Admin/>)
    expect(tree.toJSON()).toMatchSnapshot();
})
})

describe('Patient Snapshot Test',()=>{
  test('Checking Snapshot', () => {
    let tree=create(<Patient/>)
    expect(tree.toJSON()).toMatchSnapshot();
})
})

describe('Doctor Snapshot Test',()=>{
  test('Checking Snapshot', () => {
    let tree=create(<Doctor/>)
    expect(tree.toJSON()).toMatchSnapshot();
})
})

describe('Footer Snapshot Test',()=>{
  test('Checking Snapshot', () => {
    let tree=create(<Footer/>)
    expect(tree.toJSON()).toMatchSnapshot();
})
})
