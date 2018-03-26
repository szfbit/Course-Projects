<%@page import="beanClass.PurRecord"%>
<!DOCTYPE>
<html>
<head>
<title>Remark</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/navigation.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/favorite.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<jsp:useBean id="fav" type="beanClass.Fav" scope="session" />
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

			<div id="cartCheck">
				<button id="cartB" onclick="location.href='cart.do'">Cart</button>
				<button id="checkB" onclick="location.href='pay.do'">Check</button>
			</div>
		</div>

		<div id="menu">
			<ul class="menuClass">
				<li><a href="<%= request.getContextPath()%>/index">Homepage</a></li>
				<li><a href="<%= request.getContextPath()%>/Classification">Classification</a></li>
				<li><a href="<%= request.getContextPath()%>/Onsale">On Sale</a></li>
			</ul>
		</div>
 		
 		<div id="nav" class="navClass">
 			<a href="<%= request.getContextPath()%>/userInfo.jsp">User information</a><hr/>
 			<a href="#">Purchase record</a><hr/>
 			<a href="<%= request.getContextPath()%>/revisePswd.jsp">Revise password</a><hr/>
 			<a href="#">Favorite</a><hr/>
 			<a href="<%= request.getContextPath()%>/myRemark.jsp">My remark</a><hr/>
 		</div>

 		<div id="remarkB">
                        <span id="error" style='color: red'>
                        <%String error=request.getParameter("error");
                        if(error!=null){
                            if(error.equals("c1")){%>
                                no item to update!
                            <%}else if(error.equals("c2")){%>
                                no item to delete!
                            <%}else if(error.equals("c3")){%>
                                duplicate addition!
                            <%}else if(error.equals("f1")){%>
                                duplicate addition!
                            <%}else if(error.equals("f2")){%>
                                no item to delete!
                            <%}else{%>
                                Other error!                            
                            <%}}%>
                        </span>                    
                        <table id="table">
                        <thead>
                            <tr>
                                <td class="bid">Book ID</td>
                                <td class="title">Title</td>
                                <td class="pic">Front Page</td>
                                <td class="ref">Remove</td>
                            </tr>                    
                        </thead>
                        <tbody>
                            <%for(int i=0;i<=fav.getCount()-1;i++){%>
                            <tr>
                                <td class="bid"><%=fav.getLists().get(i).getId()%></td>
                                <td class="title"><%=fav.getLists().get(i).getName()%></td>
                                <td class="pic">
                                    <a href="bookInfoDisplay?bookID=<%=fav.getLists().get(i).getId()%>">
                                        <img id="bookImg" src="images/bookImages/<%=fav.getLists().get(i).getId()%>.jpg"/>
                                    </a>
                                </td>
                                <td class="ref">
                                    <a href="fav.do?action=delete&bid=<%=fav.getLists().get(i).getId()%>">
                                        Remove
                                    </a>
                                </td>
                            </tr>
                            <%}%>
                        </tbody>
                            <tr>
                                <td colspan=6 class="sum"><span class="summ"><%=fav.getCount()%> item(s)</span></td>
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