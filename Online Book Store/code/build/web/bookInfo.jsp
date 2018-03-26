<%@page import="beanClass.Fav"%>
<%@page import="java.io.BufferedReader"%>
<%@page import="java.io.File"%>
<!DOCTYPE>
<html>
<head>
<title>Book Info</title>
<link href="css/wrapper.css" rel="stylesheet" type="text/css" media="screen" />
<link href="css/bookinfo.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="js/remarkStar.js"></script>
</head>
<jsp:useBean id="bookSelected" type="beanClass.Book" scope="session"/>
<jsp:useBean id="bookDes" type="beanClass.bookDesc" scope="session"/>
<jsp:useBean id="account" type="beanClass.User" scope="session"/>
<jsp:useBean id="rmk" type="beanClass.Remark" scope="session"/>
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
 	
 		<div id="bookSelected">
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
 			<table id="book">
 				<tr>
 					<td id="imgtd" rowspan="7"><img id="bookimg" src="images/bookImages/<jsp:getProperty name='bookSelected' property='id'/>.jpg"/></td>
 				</tr>

 				<tr>
 					<td class="tdClass" title="<jsp:getProperty name='bookSelected' property='name'/>">Name: <jsp:getProperty name='bookSelected' property='name'/></td>
 				</tr>

 				<tr>
 					<td>Author: <jsp:getProperty name='bookSelected' property='author'/></td>
 				</tr>

 				<tr>
 					<td>Publish time: <jsp:getProperty name='bookSelected' property='publish_time'/></td>
 				</tr>

 				<tr>
 					<td>ISBN: <jsp:getProperty name='bookSelected' property='ISBN'/></td>
 				</tr>

 				<tr>
 					<td class="priceClass">Price: $<jsp:getProperty name='bookSelected' property='current_price'/></td>
 				</tr>

                               
 				<tr>
 					<td><button onclick="location.href='cart.do?action=add&id=<%=bookSelected.getId()%>'">add to cart</button> 
                                            <%if(!session.getAttribute("login").equals("false")){
                                                String dis,url;
                                                if(((Fav)session.getAttribute("fav")).find(bookSelected.getId())){
                                                    dis="delete from favorite";
                                                    url="fav.do?action=delete&bid="+bookSelected.getId();
                                                }
                                                else
                                                {
                                                    dis="add to favorite";
                                                    url="fav.do?action=add&bid="+bookSelected.getId();
                                                }
                                                %>
                                                <button onclick="location.href='<%=url%>'" ><%=dis%></button>
                                            <%}%>
                                        </td>
 				</tr>
 			</table>
 			
 			<div class="titleStyle">
 				description
 			</div>
                    
 			<div id="description">
 				<p id="desP"><jsp:getProperty name="bookDes" property="des"/></p>
 			</div>

 			<div class="titleStyle">Remark</div>
                        <% if(rmk.getNum() == 0){%>
                            <p>No Remarks</p>
                        <%} else{
                            for(int i = 0; i < rmk.getNum(); i++)
                            {%>
                            <p><%= rmk.getEmail(i)%></p>
                            <p><img id="starImg" src="images/remarkImages/<%= rmk.getStar(i)%>-star.png"/></p>
                            <p><%= rmk.getRemark(i)%></p>
                            <hr/>
                            <%}
                        }%>
                           
                        <form method="POST" action="<%= request.getContextPath()%>/RemarkStorage">
                            <div id="remark">
                                <input type="hidden" name="bookid" value="<%=bookSelected.getId()%>"/>
                                <input type="hidden" name="usremail" value="<%=account.getEmail()%>"/>
                                <div id="starB">
                                            <img id="s1" src="images/remarkImages/star_B.png" onmouseover="changeStar(1);" onmouseout="resetS();" onclick="confirm(1);"/>
                                            <img id="s2" src="images/remarkImages/star_B.png" onmouseover="changeStar(2);" onmouseout="resetS();" onclick="confirm(2);"/>
                                            <img id="s3" src="images/remarkImages/star_B.png" onmouseover="changeStar(3);" onmouseout="resetS();" onclick="confirm(3);"/>
                                            <img id="s4" src="images/remarkImages/star_B.png" onmouseover="changeStar(4);" onmouseout="resetS();" onclick="confirm(4);"/>
                                            <img id="s5" src="images/remarkImages/star_B.png" onmouseover="changeStar(5);" onmouseout="resetS();" onclick="confirm(5);"/>
                                </div>
                                <input type="hidden" id="star" name="star" value="0"/>
                                <textarea id="comment" name="comment" maxlength="250"></textarea>
                            </div>
                            
                            <div id="submitB">
                                    <button type="submit" id="submit">submit</button>
                            </div>
                        </form>
 		</div>


		<div id="footer">
			<p>Author: WANG Yiji(52639040), ZOU Shaokun(52639296)</p>
			<p>All Rights Reserved</p>
		</div>
	</div>
</body>
</html>