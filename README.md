Name: Abia Khan and Mario Salinas 


NetID: ac6212 and ry7931


Phase 2


Bank Management System Software Design Document
Table of Contents
Introduction
Purpose of the Document
Scope of the Project
Overview of the Bank Management System
System Architecture
High-Level System Architecture
Key Components
System Dependencies
Data Flow Diagram
System Requirements
Functional Requirements
User Authentication
Customer Account Management
Transaction Processing
Reporting
Non-functional Requirements
Performance
Security
Scalability
Usability
Use Cases
Use Case Diagram
Detailed Use Case Descriptions
Login
Create Account
Deposit
Withdraw
Transfer
View Balance
Generate Reports
Turn bank-issued card On/Off
Apply for loan
Logout
Class Diagram
Class Diagram Overview
Class Descriptions
User
- string username
- string password
Account
- int balance
- GetBalance();
- Deposit();
- Withdraw();
Transaction
Loan Application
- int socialSecurityNumber
- int income
- int address
- int monthlyExpenses
- int creditScore
- PutSSN();
- PutIncome();
- PutAddress();
- PutMonthlyExpenses();
- PutCreditScore();
Report
Database Design
Entity-Relationship Diagram (ERD)
Database Schema
User Table
Customer Table
Account Table
Transaction Table
Report Table
User Interface Design
Mockup Screens
User Interface Flow
User Interaction Details
Software Development Environment
Programming Language: C++
IDE/Tools - CLion and VS Code and BlackBox
Libraries/Frameworks - 
Coding Standards
Naming Conventions
Coding Style Guidelines
Testing
Test Plan
Create assert statements using every class
Test Cases
Test Data
Test Execution and Reporting
Deployment
Deployment Environment
Installation Instructions
Maintenance and Support
Ongoing Maintenance Plan
Support Contact Information
Security
Authentication and Authorization
Data Encryption
Security Protocols
Scalability
Scalability Plan
Load Balancing
Backup and Recovery
Backup Strategy
Disaster Recovery Plan
Documentation
User Manual
Developer Documentation
API Documentation (if applicable)
Appendices
Glossary of Terms
References
Version History
Conclusion
This Bank Management System design document provides an overview of the system architecture, requirements, use cases, class diagrams, database design, user interface design, and other important aspects of the software. It serves as a guide for developers, testers, and maintainers throughout the project lifecycle.
Please note that this is a generic template, and you should adapt it to the specific requirements and complexities of your Bank Management System project. Additionally, it's important to involve relevant stakeholders, such as bank staff and customers, in the design and validation process to ensure the system meets their needs.

