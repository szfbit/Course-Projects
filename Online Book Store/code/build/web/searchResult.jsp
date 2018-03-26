<!DOCTYPE>
<html>
<head>
<title>Search Result</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/ADMIN_Books.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/ADMIN_reviseBookQty.js"></script>
</head>
<jsp:useBean id="searchResult" type="beanClass.ADMIN_Book" scope="request"/>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
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
                            <a href="Logout">Log out</a>
                            <%}%>
			</nav>

		</div>

		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/ADMIN_allbooks">Books</a></li>
				<li><a href="<%= request.getContextPath()%>/ADMIN_allusers">Users</a></li>
				<li><a href="#">Statistics</a></li>
				<li><a href="#">Requests</a></li>
			</ul>
		</div>
 		
 		<div id="tb">
 			<table id="booksT">
                            <% if(searchResult.getNum()==0)
                            {%>
                            <tr><td>No result</td></tr>
                            <%}else{%>
                            <tr>
 				<td>BookID</td>
 				<td>Img</td>
 				<td>Name</td>
 				<td>Category</td>
                                <td>Quantity</td>
 				<td>Price($)</td>
                                
                            </tr>
                            <% for(int i = 0; i < searchResult.getNum(); i++)
                            {%>
                                <tr>
                                    <td><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=searchResult.getBook(i).getId()%>"><%=searchResult.getBook(i).getId()%></a></td>
                                    <td><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=searchResult.getBook(i).getId()%>"><img src="images/bookImages/<%=searchResult.getBook(i).getId()%>.jpg"/></a></td>
                                    <td class="nameTD" title="<%=searchResult.getBook(i).getName()%>"><a href="<%= request.getContextPath()%>/bookInfoDisplay?bookID=<%=searchResult.getBook(i).getId()%>"><%=searchResult.getBook(i).getName()%></a></td>
                                    <td><%=searchResult.getBook(i).getCat()%></td>
                                    <td><%=searchResult.getBook(i).getQty()%></td>
                                    <td><%=searchResult.getBook(i).getCurrent_price()%></td>
                                   
                                </tr>
                            <%}}%>
 				
 			</table>
 		</div>

		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>