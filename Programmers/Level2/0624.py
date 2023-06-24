# https://school.programmers.co.kr/learn/courses/30/lessons/72411

def solution(orders, course):
    
    import itertools, collections
    
    answer = []
    
    for c in course:
        order_dict = collections.defaultdict(int)
        order_combi = []
        
        for order in orders:
            order_combi.extend(list(itertools.combinations(sorted(order), c)))
    
        for order_c in order_combi:
            o_str = "".join(order_c)
            order_dict[o_str]+=1
        
        for x,y in order_dict.items():
            if y>=2 and y == max([ y for y in order_dict.values()]):
                answer.append(x)
                
    answer.sort() 
    return answer
