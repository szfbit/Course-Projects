<!DOCTYPE>
<html>
<head>
<title>ADMIN-Books</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/ADMIN_Books.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/ADMIN_reviseBookQty.js"></script>
</head>
<jsp:useBean id="ADbook" type="beanClass.ADMIN_Book" scope="session"/>
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
 		
 		<div id="tb">
 			<table id="booksT">
                            <tr>
 				<td>BookID</td>
 				<td>Img</td>
 				<td>Name</td>
 				<td>Category</td>
                                <td>Quantity</td>
 				<td>Price($)</td>
                                
                            </tr>
                            <% for(int i = 0; i < ADbook.getNum(); i++)
                            {%>
                                <tr>
                                    <td id="bookIDB" value="<%=ADbook.getBook(i).getId()%>"><%=ADbook.getBook(i).getId()%></td>
                                    <td><img src="images/bookImages/<%=ADbook.getBook(i).getId()%>.jpg"/></td>
                                    <td class="nameTD" title="<%=ADbook.getBook(i).getName()%>"><%=ADbook.getBook(i).getName()%></td>
                                    <td><%=ADbook.getBook(i).getCat()%></td>
                                    <td><form id="f<%=i%>" action="<%= request.getContextPath()%>/ADMIN_ReviseBookQty">
                                            <input name="BookID" type="hidden" value="<%=ADbook.getBook(i).getId()%>"/>
                                            <input id="qty<%=i%>" name="qty"  type="text"  value="<%=ADbook.getBook(i).getQty()%>"/>
                                            <button id="Btn<%=i%>" onclick="clickB(<%=i%>);">edit</button>
                                        </form>
                                    </td>
                                    <td>
                                        <form id="fp<%=i%>"action="<%= request.getContextPath()%>/ADMIN_ReviseBookPrice">
                                            <input name="BookID" type="hidden" value="<%=ADbook.getBook(i).getId()%>"/>
                                            <input id="prc<%=i%>" name="price" type="text" value="<%=ADbook.getBook(i).getCurrent_price()%>"/>
                                            <button id="Btnp<%=i%>" onclick="clickBp(<%=i%>);">edit</button>
                                        </form>
                                    </td>
                                   
                                </tr>
                            <%}%>
 				
 			</table>
 		</div>

		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>

	</div>
</body>
</html>