<!DOCTYPE>
<html>
<head>
<title>ADMIN-Books</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/ADMIN_Books.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/ADMIN_Refund.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/ADMIN_reviseBookQty.js"></script>
</head>
<jsp:useBean id="ADbook" type="beanClass.ADMIN_Book" scope="session"/>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<jsp:useBean id="record" type="beanClass.RefRecord" scope="request"/>
<body>
	<div id="wrapper">
		<div id="upper">
			<div id="logoBlock">
				<img id="logo" src="images/logo.png"/>
			</div>

			<div id="search">
                            <form action="<%= request.getContextPath()%>/Search" method="POST">
				<img id="searchImage" src="images/search.png"/>
                                <select id="selectS" name="tp">
                                    <option value="Name">Name</option>
                                    <option value="Author">Author</option>
                                    <option value="BookID">BookID</option>
                                    <option value="Publisher">Publisher</option>                               
                                </select>
                                <input name="keyWd" id="searchText" type="text" placeholder="Search" />
				<button id="searchButton" type="submit">Search</button> 
                            </form>
			</div>

			<nav id="loginReg">
				<%if(session.getAttribute("login").equals("false")){ %>
				<a href="login.jsp">log in</a>
				<a href="register.jsp">Register</a>
                            <%}else{%>
                            <a href="userInfo.jsp"><jsp:getProperty name="account" property="userName" /></a>
                                    <a href="#">Log out</a>
                            <%}%>
			</nav>

		</div>

		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/ADMIN_allbooks">Books</a></li>
				<li><a href="<%= request.getContextPath()%>/ADMIN_allusers">Users</a></li>
				<li><a href="<%= request.getContextPath()%>/ADMIN_StaReport">Statistics</a></li>
				<li><a href="refund.do">Requests</a></li>
			</ul>
		</div>
 		
                <div id="tableContainer">
                    <table id="table">
                    <thead>
                        <tr>
                            <td class="pid">Purchase ID</td>
                            <td class="bid">Book ID</td>
                            <td class="qty">Quantity</td>
                            <td class="subt">Charge</td>
                            <td class="sending">Sending Status</td>
                            <td class="ref">Operation</td>
                        </tr>                    
                    </thead>
                    <tbody>
                        <%double total=0;%>
                        <%for(int i=0;i<=record.getCount()-1;i++){%>
                        <tr>
                            <td class="pid"><%=record.getPidList().get(i)%></td>
                            <td class="bid"><%=record.getbList().get(i).getId()%></td>
                            <td class="qty"><%=record.getNum().get(i)%></td>
                            <td class="subt"><%=record.getCharList().get(i)%></td>
                            <td class="sending"><b>
                                <%if(record.getCharList().get(i)==0){%>
                                    Out of Stack
                                <%}else{%>
                                    Sending
                                <%}%>
                                </b>
                            </td>
                            <td class="ref">
                                <%if(record.getStaList().get(i)==0){%>
                                <%String url1="refund.do?action=accept&email="+record.getEmailList().get(i)+"&rid="+record.getRidList().get(i);
                                String url2="refund.do?action=reject&rid="+record.getRidList().get(i);
                                %>
                                    
                                    <a href="<%=url1%>">Accept</a>
                                    <a href="<%=url2%>">Reject</a>
                                <%}else if(record.getStaList().get(i)==1){%>
                                    Approved.
                                <%}else{%>
                                    Rejected.
                                <%}%> 
                            </td>
                        </tr>
                        <%}%>
                    </tbody>
                        <tr>
                            <td colspan=6 class="sum"><span class="summ"><%=record.getCount()%> item(s)</span></td>
                        </tr>
                    </table>
                </div>             


		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>